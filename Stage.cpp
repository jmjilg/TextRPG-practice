
#include "Stage.h"
#include "value.h"
#include "Monster.h"
#include "Player.h"

CStage::CStage()
{
}

CStage::~CStage()
{
}

void CStage::OutputStageName(char* pName)
{
	cout << "========================	" << pName << " ========================" << endl;
}

int CStage::OutputMenu()
{
	while (true)
	{
		system("cls");
		cout << "1. 공격" << endl;
		cout << "2. 도망간다" << endl;
		cout << "행동을 선택하세요 : ";
		int input;
		input = IntInput<int>();

		if (input <= (int)BATTLE::NONE || input > (int)BATTLE::RUN_AWAY)
			continue;

		return input;
	}
}

CStage::BATTLE_FLAG CStage::BattleAttack(CPlayer* pPlayer, CMonster* pMonster)
{
	int iDamage = pPlayer->GetDamage();
	int iArmor = pMonster->GetArmor();

	iDamage = iDamage <= iArmor ? 1 : iDamage - iArmor;

	
	

	// 플레이어가 몬스터 쓰려뜨렸을 시
	if (pMonster->Die(iDamage))
	{
		return BATTLE_FLAG::PLAYER_WIN;
		
		//// 골드 획득
		//pPlayer->iGold += pMonster->iGold;

		//// 경험치 획득
		//pPlayer->m_pInfo->iExp += pMonster->m_pInfo->iExp;

		//// 몬스터 초기화
		//pMonster->m_pInfo->iHP = pMonster->m_pInfo->iHPmax;

		//cout << "고블린을 해치웠다!" << endl;
		//system("pause");

		//return;
	}

	// 몬스터가 플레이어 공격
	iDamage = pMonster->GetDamage();
	iArmor = pPlayer->GetArmor();

	iDamage = iDamage <= iArmor ? 1 : iDamage - iArmor;


	// 플레이어가 몬스터에게 패배했을 시
	if (pPlayer->Die(iDamage))
	{

		return BATTLE_FLAG::PLAYER_DIE;
		//// 골드 10% 드랍
		//pPlayer->iGold *= 0.9f;

		//// 경험치 10% 드랍
		//pPlayer->m_pInfo->iExp *= 0.9f;

		//// 플레이어 초기화
		//pPlayer->m_pInfo->iHP = pPlayer->m_pInfo->iHPmax;

		//cout << "플레이어가 쓰러졌습니다.." << endl;
		//system("pause");

		//return;
	}
}

