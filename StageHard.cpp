#include "StageHard.h"

CStageHard::CStageHard()
{
}

CStageHard::~CStageHard()
{
}

void CStageHard::Init()
{
	CMonster* pMonster = new CMonster;
	pMonster->SetCharacterInfo("드래곤", 100, 150, 50, 70, 1000, 500, 10000, 10, 30000);
}

void CStageHard::Run(CPlayer* pPlayer)
{
	while (true)
	{
		system("cls");
		m_pMonster->Render();
		pPlayer->Render();
		cout << "1. 공격" << endl;
		cout << "2. 도망간다" << endl;
		cout << "행동을 선택하세요 : ";
		int input;
		input = IntInput<int>() - 1;
		switch (input)
		{
		case (int)BATTLE::ATTACK:
			Battle(pPlayer, m_pMonster);
			break;
		case (int)BATTLE::RUN_AWAY:
			return;
		default:
			continue;
		}
	}
}

void CStageHard::Battle(CPlayer* pPlayer, CMonster* pMonster)
{
	// 플레이어가 몬스터 공격
	int iDamage = rand() % (pPlayer->m_pInfo->iMaxDamage - pPlayer->m_pInfo->iMinDamage + 1) +
		pPlayer->m_pInfo->iMinDamage;
	int iArmor = rand() % (pMonster->m_pInfo->iMaxArmor - pMonster->m_pInfo->iMinDamage + 1) +
		pMonster->m_pInfo->iMinArmor;

	iDamage = iDamage <= iArmor ? 1 : iDamage - iArmor;

	pMonster->m_pInfo->iHP -= iDamage;

	// 플레이어가 몬스터 쓰려뜨렸을 시
	if (pMonster->m_pInfo->iHP <= 0)
	{
		// 골드 획득
		pPlayer->iGold += pMonster->iGold;

		// 경험치 획득
		pPlayer->m_pInfo->iExp += pMonster->m_pInfo->iExp;

		// 몬스터 초기화
		pMonster->m_pInfo->iHP = pMonster->m_pInfo->iHPmax;

		cout << "고블린을 해치웠다!" << endl;
		system("pause");

		return;
	}

	// 몬스터가 플레이어 공격
	iDamage = rand() % (pMonster->m_pInfo->iMaxDamage - pMonster->m_pInfo->iMinDamage + 1) +
		pMonster->m_pInfo->iMinDamage;
	iArmor = rand() % (pPlayer->m_pInfo->iMaxArmor - pPlayer->m_pInfo->iMinDamage + 1) +
		pPlayer->m_pInfo->iMinArmor;

	iDamage = iDamage <= iArmor ? 1 : iDamage - iArmor;

	pPlayer->m_pInfo->iHP -= iDamage;

	// 플레이어가 몬스터에게 패배했을 시
	if (pPlayer->m_pInfo->iHP <= 0)
	{
		// 골드 10% 드랍
		pPlayer->iGold *= 0.9f;

		// 경험치 10% 드랍
		pPlayer->m_pInfo->iExp *= 0.9f;

		// 플레이어 초기화
		pPlayer->m_pInfo->iHP = pPlayer->m_pInfo->iHPmax;

		cout << "플레이어가 쓰러졌습니다.." << endl;
		system("pause");

		return;
	}
}
