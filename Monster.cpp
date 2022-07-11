
#include "Monster.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
}

bool CMonster::Init()
{
	m_iGoldMin = 0;
	m_iGoldMax = 0;

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


