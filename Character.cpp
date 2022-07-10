
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
	cout << "이름 : " << m_Info.name << "\t경험치 : " << m_Info.iExp << endl;
	cout << "공격력 : " << m_Info.iMinDamage << "~" << m_Info.iMaxDamage <<
		"\t방어력 : " << m_Info.iMinArmor << "~" << m_Info.iMaxArmor << endl;
	cout << "체력 : " << m_Info.iHP << "/" << m_Info.iHPmax << "\t마력 : " <<
		m_Info.iMP << "/" << m_Info.iMPmax << endl;
	cout << "레벨 : " << m_Info.iLevel;
}
