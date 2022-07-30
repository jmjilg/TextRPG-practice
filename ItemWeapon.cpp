#include "ItemWeapon.h"
#include "FileStream.h"

CItemWeapon::CItemWeapon()
{
	m_eType = OBJECT_TYPE::WEAPON;
}

CItemWeapon::~CItemWeapon()
{
}

void CItemWeapon::Render()
{
	cout << "�̸� : " << m_strName << "\t���� : " << m_tInfo.strTypeName << endl;
	cout << "���ݷ� : " << m_iAttackMin << " ~ " << m_iAttackMax << endl;
	cout << "Price : " << m_tInfo.iPrice << "\tSell : " << m_tInfo.iSell << endl;
	cout << "���� : " << m_tInfo.strDesc << endl << endl;
}

CItem* CItemWeapon::Clone()
{
	return new CItemWeapon(*this);
}

void CItemWeapon::Save(CFileStream* pFile)
{
	CItem::Save(pFile);

	pFile->Write(&m_iAttackMin, 4);
	pFile->Write(&m_iAttackMax, 4);
	pFile->Write(&m_fCritical, sizeof(m_fCritical));

}

void CItemWeapon::Load(CFileStream* pFile)
{
	CItem::Load(pFile);

	pFile->Read(&m_iAttackMin, 4);
	pFile->Read(&m_iAttackMax, 4);
	pFile->Read(&m_fCritical, sizeof(m_fCritical));
}
