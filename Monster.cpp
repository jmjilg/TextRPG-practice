
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
	cout << "�̸� : " << m_pInfo->name << endl;
	cout << "���ݷ� : " << m_pInfo->iMinDamage << "~" << m_pInfo->iMaxDamage <<
		"\t���� : " << m_pInfo->iMinArmor << "~" << m_pInfo->iMaxArmor << endl;
	cout << "ü�� : " << m_pInfo->iHP << "/" << m_pInfo->iHPmax << "\t���� : " <<
		m_pInfo->iMP << "/" << m_pInfo->iMPmax << endl;
	cout << "���� : " << m_pInfo->iLevel << "\t������ : " << iGold << endl << endl;
}
