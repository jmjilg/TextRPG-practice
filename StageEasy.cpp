#include "StageEasy.h"
#include "Monster.h"
#include "Player.h"
#include "Obj.h"
#include "ObjectManager.h"
#include "value.h"

CStageEasy::CStageEasy()
{
}

CStageEasy::~CStageEasy()
{
}

bool CStageEasy::Init()
{
	return true;
}

void CStageEasy::Run()
{
	CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->CloneObject("Player");
	CMonster* pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject("Goblin");


	while (true)
	{
		system("cls");
		OutputStageName("Easy");
		pPlayer->Render();
		pMonster->Render();
		
		int input = OutputMenu();

		if (input == (int)BATTLE::RUN_AWAY)
			return;

		//공격을 선택했을 시
		switch (BattleAttack(pPlayer, pMonster))
		{
		case BATTLE_FLAG::PLAYER_WIN:
			// 골드 획득
			pPlayer->SetGold(pMonster->GetGold());

			// 경험치 획득
			pPlayer->SetExp(pMonster->GetExp());

			// 몬스터 초기화
			pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject("Goblin");

			cout << "고블린을 해치웠다!" << endl;
			system("pause");
			break;
		case BATTLE_FLAG::PLAYER_DIE:
			// 골드 10% 드랍
			pPlayer->SetGold(pPlayer->GetGold() * -0.1f);

			// 경험치 10% 드랍
			pPlayer->SetExp(pPlayer->GetExp() * -0.1f);

			// 플레이어 체력 회복
			pPlayer->Heal();

			// 몬스터 초기화
			pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject("Goblin");

			cout << "플레이어가 쓰러졌습니다.." << endl;
			system("pause");
			break;
		}
	}
}

