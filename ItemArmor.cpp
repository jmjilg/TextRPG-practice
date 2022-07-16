#include "ItemArmor.h"

CItemArmor::CItemArmor()
{
}

CItemArmor::~CItemArmor()
{
}


void CItemArmor::Render()
{
	cout << "이름 : " << m_strName << "\t종류 : " << m_tInfo.strTypeName << endl;
	cout << "방어력 : " << m_iArmorMin << " ~ " << m_iArmorMax << endl;
	cout << "Price : " << m_tInfo.iPrice << "\tSell : " << m_tInfo.iSell << endl;
	cout << "설명 : " << m_tInfo.strDesc << endl << endl;
}

CObj* CItemArmor::Clone()
{
	return new CItemArmor(*this);
}


