
#include "Character.h"

CCharacter::CCharacter()
{
}

CCharacter::~CCharacter()
{
}


void CCharacter::SetCharacterInfo(const char* name, int iMinDamage, int iMaxDamage,
	int	iMinArmor, int	iMaxArmor, int iHP, int iMP, int iExp, int iLevel)
{
	m_tInfo.iMinDamage = iMinDamage;
	m_tInfo.iMaxDamage = iMaxDamage;
	m_tInfo.iMinArmor = iMinArmor;
	m_tInfo.iMaxArmor = iMaxArmor;
	m_tInfo.iHPmax = iHP;
	m_tInfo.iHP = iHP;
	m_tInfo.iMPmax = iMP;
	m_tInfo.iMP = iMP;
	m_tInfo.iExp = iExp;
	m_tInfo.iLevel = iLevel;
	strcpy_s(m_tInfo.name, NAME_LENGTH, name);
}

int CCharacter::GetDamage()
{
	return rand() % (m_tInfo.iMaxDamage - m_tInfo.iMinDamage + 1) +
		m_tInfo.iMinDamage;
}

int CCharacter::GetArmor()
{
	return rand() % (m_tInfo.iMaxArmor - m_tInfo.iMinDamage + 1) +
		m_tInfo.iMinArmor;
}

bool CCharacter::Die(int iDamage)
{
	m_tInfo.iHP -= iDamage;

	if(m_tInfo.iHP <= 0)
		return true;

	return false;
}

bool CCharacter::Init()
{
	return false;
}

CObj* CCharacter::Clone()
{
	return nullptr;
}

void CCharacter::Render()
{
	cout << "�̸� : " << m_tInfo.name << "\t����ġ : " << m_tInfo.iExp << endl;
	cout << "���ݷ� : " << m_tInfo.iMinDamage << "~" << m_tInfo.iMaxDamage <<
		"\t���� : " << m_tInfo.iMinArmor << "~" << m_tInfo.iMaxArmor << endl;
	cout << "ü�� : " << m_tInfo.iHP << "/" << m_tInfo.iHPmax << "\t���� : " <<
		m_tInfo.iMP << "/" << m_tInfo.iMPmax << endl;
	cout << "���� : " << m_tInfo.iLevel;
}
