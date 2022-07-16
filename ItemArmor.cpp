#include "ItemArmor.h"

CItemArmor::CItemArmor()
{
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

CObj* CItemArmor::Clone()
{
	return new CItemArmor(*this);
}


