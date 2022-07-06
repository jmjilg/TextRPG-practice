
#include "Monster.h"

CMonster::CMonster()
{
	m_pInfo = new CHARACTER;
}

CMonster::~CMonster()
{
	delete m_pInfo;
}


void CMonster::Create(const char* name, int iMinDamage, int iMaxDamage,
	int	iMinArmor, int	iMaxArmor, int iHP, int iMP, int iExp, int iLevel, int iGold)
{
	this->m_pInfo->iMinDamage = iMinDamage;
	this->m_pInfo->iMaxDamage = iMaxDamage;
	this->m_pInfo->iMinArmor = iMinArmor;
	this->m_pInfo->iMaxArmor = iMaxArmor;
	this->m_pInfo->iHPmax = iHP;
	this->m_pInfo->iHP = iHP;
	this->m_pInfo->iMPmax = iMP;
	this->m_pInfo->iMP = iMP;
	this->m_pInfo->iExp = iExp;
	this->m_pInfo->iLevel = iLevel;
	strcpy_s(this->m_pInfo->name, NAME_LENGTH, name);
	this->iGold = iGold;
}

void CMonster::Info()
{
	cout << "이름 : " << m_pInfo->name << endl;
	cout << "공격력 : " << m_pInfo->iMinDamage << "~" << m_pInfo->iMaxDamage <<
		"\t방어력 : " << m_pInfo->iMinArmor << "~" << m_pInfo->iMaxArmor << endl;
	cout << "체력 : " << m_pInfo->iHP << "/" << m_pInfo->iHPmax << "\t마력 : " <<
		m_pInfo->iMP << "/" << m_pInfo->iMPmax << endl;
	cout << "레벨 : " << m_pInfo->iLevel << "\t소지금 : " << iGold << endl << endl;
}
