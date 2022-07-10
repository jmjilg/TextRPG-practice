
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
	m_Info.iMinDamage = iMinDamage;
	m_Info.iMaxDamage = iMaxDamage;
	m_Info.iMinArmor = iMinArmor;
	m_Info.iMaxArmor = iMaxArmor;
	m_Info.iHPmax = iHP;
	m_Info.iHP = iHP;
	m_Info.iMPmax = iMP;
	m_Info.iMP = iMP;
	m_Info.iExp = iExp;
	m_Info.iLevel = iLevel;
	strcpy_s(m_Info.name, NAME_LENGTH, name);
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
	cout << "�̸� : " << m_Info.name << "\t����ġ : " << m_Info.iExp << endl;
	cout << "���ݷ� : " << m_Info.iMinDamage << "~" << m_Info.iMaxDamage <<
		"\t���� : " << m_Info.iMinArmor << "~" << m_Info.iMaxArmor << endl;
	cout << "ü�� : " << m_Info.iHP << "/" << m_Info.iHPmax << "\t���� : " <<
		m_Info.iMP << "/" << m_Info.iMPmax << endl;
	cout << "���� : " << m_Info.iLevel;
}
