
#include "Monster.h"
#include "ObjectManager.h"
#include "FileStream.h"

CMonster::CMonster()
{
	m_eType = OBJECT_TYPE::MONSTER;
}

CMonster::CMonster(const CMonster& monster)	:
	CCharacter(monster)
{
	m_iGoldMin = monster.m_iGoldMin;
	m_iGoldMax = monster.m_iGoldMax;
	m_eStageLevel = monster.m_eStageLevel;
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
	cout << "\t소지금 : " << m_iGoldMin << "~" << m_iGoldMax << endl;
	cout << "난이도 : ";
	switch (m_eStageLevel)
	{
	case STAGE_LEVEL::EASY:
		cout << "쉬움" << endl;
		break;
	case STAGE_LEVEL::NORMAL:
		cout << "보통" << endl;
		break;
	case STAGE_LEVEL::HARD:
		cout << "어려움" << endl;
		break;
	}
	cout << endl;
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

void CMonster::Save(CFileStream* pFile)
{
	CCharacter::Save(pFile);
	pFile->Write(&m_iGoldMin, 4);
	pFile->Write(&m_iGoldMax, 4);
	pFile->Write(&m_eStageLevel, 4);
}

void CMonster::Load(CFileStream* pFile)
{
	CCharacter::Load(pFile);	
	pFile->Read(&m_iGoldMin, 4);
	pFile->Read(&m_iGoldMax, 4);
	pFile->Read(&m_eStageLevel, 4);
}


