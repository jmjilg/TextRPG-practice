#include "Item.h"

CItem::CItem()
{
}

CItem::CItem(const CItem& item) :
	CObj(item)
{
	m_tInfo = item.m_tInfo;
}


CItem::~CItem()
{
}

bool CItem::Init()
{
	return true;
}

void CItem::SetItemInfo(ITEM_TYPE eType, int iPrice, int iSell, const char* pDesc)
{
	m_tInfo.eType = eType;

	switch (eType)
	{
	case ITEM_TYPE::WEAPON:
		m_tInfo.strTypeName = "무기";
		break;
	case ITEM_TYPE::ARMOR:
		m_tInfo.strTypeName = "방어구";
		break;
	}

	m_tInfo.iPrice = iPrice;
	m_tInfo.iSell = iSell;
	strcpy_s(m_tInfo.strDesc, pDesc);
}

void CItem::Save(CFileStream* pFile)
{
	CObj::Save(pFile);
}

void CItem::Load(CFileStream* pFile)
{
	CObj::Load(pFile);
}

