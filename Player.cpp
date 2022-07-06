
#include "Player.h"

CPlayer::CPlayer()
{
	m_pInfo = new CHARACTER;
}

CPlayer::~CPlayer()
{
	delete m_pInfo;
}

void CPlayer::Init()
{
}
void CPlayer::Create(const char* name, int iMinDamage, int iMaxDamage,
	int	iMinArmor, int	iMaxArmor, int iHP, int iMP, int iExp, int iLevel)
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
}
