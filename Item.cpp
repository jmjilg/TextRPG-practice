#include "Item.h"
#include "FileStream.h"

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

	pFile->Write(&m_tInfo.eType, sizeof(m_tInfo.eType));

	int iLength = m_tInfo.strTypeName.length();

	pFile->Write(&iLength, 4);

	pFile->Write((void*)m_tInfo.strTypeName.c_str(), iLength);

	pFile->Write(&m_tInfo.iPrice, 4);
	pFile->Write(&m_tInfo.iSell, 4);

	pFile->Write((void*)m_tInfo.strDesc, STR_DESC_LENGTH);

}

void CItem::Load(CFileStream* pFile)
{
	CObj::Load(pFile);

	pFile->Read(&m_tInfo.eType, sizeof(m_tInfo.eType));

	int iLength = 0;

	pFile->Read(&iLength, 4);

	char* pBuffer = new char[iLength + 1];
	memset(pBuffer, 0, iLength);
	pBuffer[iLength] = 0;

	pFile->Read(pBuffer, iLength);

	m_tInfo.strTypeName = pBuffer;

	pFile->Read(&m_tInfo.iPrice, 4);
	pFile->Read(&m_tInfo.iSell, 4);

	pFile->Read(&m_tInfo.strDesc, STR_DESC_LENGTH);

	SAFE_DELETE(pBuffer);
}

