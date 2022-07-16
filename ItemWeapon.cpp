#include "ItemWeapon.h"

CItemWeapon::CItemWeapon()
{
}

CItemWeapon::~CItemWeapon()
{
}

void CItemWeapon::Render()
{
	cout << "�̸� : " << m_strName << "\t���� : " << m_tInfo.strTypeName << endl;
	cout << "���� : " << m_iAttackMin << " ~ " << m_iAttackMax << endl;
	cout << "Price : " << m_tInfo.iPrice << "\tSell : " << m_tInfo.iSell << endl;
	cout << "���� : " << m_tInfo.strDesc << endl << endl;
}

CObj* CItemWeapon::Clone()
{
	return new CItemWeapon(*this);
}
