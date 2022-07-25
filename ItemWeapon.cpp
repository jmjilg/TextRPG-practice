#include "ItemWeapon.h"

CItemWeapon::CItemWeapon()
{
}

CItemWeapon::~CItemWeapon()
{
}

void CItemWeapon::Render()
{
	cout << "이름 : " << m_strName << "\t종류 : " << m_tInfo.strTypeName << endl;
	cout << "공격력 : " << m_iAttackMin << " ~ " << m_iAttackMax << endl;
	cout << "Price : " << m_tInfo.iPrice << "\tSell : " << m_tInfo.iSell << endl;
	cout << "설명 : " << m_tInfo.strDesc << endl << endl;
}

CItem* CItemWeapon::Clone()
{
	return new CItemWeapon(*this);
}
