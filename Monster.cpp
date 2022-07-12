
#include "Monster.h"
#include "ObjectManager.h"

CMonster::CMonster()
{
	Init();
}

CMonster::~CMonster()
{
}

bool CMonster::Init()
{

	return true;
}

void CMonster::Render()
{
	CCharacter::Render();
	cout << "¼ÒÁö±Ý : " << m_iGoldMin << "~" << m_iGoldMax << endl << endl;
}

CObj* CMonster::Clone()
{
	return new CMonster(*this);
}

int CMonster::GetGold()
{
	return rand() % (m_iGoldMax - m_iGoldMin + 1) + m_iGoldMin;
}

int CMonster::GetExp()
{
	return m_tInfo.iExp;
}

void CMonster::SetGold(int iGoldMin, int iGoldMax)
{
	m_iGoldMin = iGoldMin;
	m_iGoldMax = iGoldMax;
}


