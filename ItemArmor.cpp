#include "ItemArmor.h"
#include "FileStream.h"

CItemArmor::CItemArmor()
{
	m_eType = OBJECT_TYPE::ARMOR;
}

CItemArmor::~CItemArmor()
{
}


void CItemArmor::Render()
{
	cout << "�̸� : " << m_strName << "\t���� : " << m_tInfo.strTypeName << endl;
	cout << "���� : " << m_iArmorMin << " ~ " << m_iArmorMax << endl;
	cout << "Price : " << m_tInfo.iPrice << "\tSell : " << m_tInfo.iSell << endl;
	cout << "���� : " << m_tInfo.strDesc << endl << endl;
}

CItem* CItemArmor::Clone()
{
	return new CItemArmor(*this);
}

void CItemArmor::Save(CFileStream* pFile)
{
	CItem::Save(pFile);

	pFile->Write(&m_iArmorMin, 4);
	pFile->Write(&m_iArmorMax, 4);
}

void CItemArmor::Load(CFileStream* pFile)
{
	CItem::Load(pFile);

	pFile->Read(&m_iArmorMin, 4);
	pFile->Read(&m_iArmorMax, 4);
}


