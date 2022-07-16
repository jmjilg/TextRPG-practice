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

void CItem::Render()
{
}

void CItem::SetItemInfo(ITEM_TYPE eType, int iPrice, int iSell, const char* pDesc)
{
	m_tInfo.eType = eType;

	switch (eType)
	{
	case ITEM_TYPE::WEAPON:
		m_tInfo.strTypeName = "����";
		break;
	case ITEM_TYPE::ARMOR:
		m_tInfo.strTypeName = "��";
		break;
	}

	m_tInfo.iPrice = iPrice;
	m_tInfo.iSell = iSell;
	strcpy_s(m_tInfo.strDesc, pDesc);
}

