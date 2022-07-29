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
	CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");
	CMonster* pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject(STAGE_LEVEL::EASY);


	while (true)
	{
		system("cls");
		OutputStageName("Easy");
		pPlayer->Render();
		pMonster->Render();
		
		int input = OutputMenu();

		if (input == (int)BATTLE::RUN_AWAY)
			return;

		//������ �������� ��
		switch (BattleAttack(pPlayer, pMonster))
		{
		case BATTLE_FLAG::PLAYER_WIN:
			// ��� ȹ��
			pPlayer->SetGold(pMonster->GetGold());

			// ����ġ ȹ��
			pPlayer->SetExp(pMonster->GetExp());

			// ���� �ʱ�ȭ
			pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject("Goblin");

			cout << "����� ��ġ����!" << endl;

			if (pPlayer->LevelupCheck())
			{
				pPlayer->Levelup(pPlayer->GetJob());
			}
			system("pause");
			break;
		case BATTLE_FLAG::PLAYER_DIE:
			// ��� 10% ���
			pPlayer->SetGold(pPlayer->GetGold() * -0.1f);

			// ����ġ 10% ���
			pPlayer->SetExp(pPlayer->GetExp() * -0.1f);

			// �÷��̾� ü�� ȸ��
			pPlayer->Heal();

			// ���� �ʱ�ȭ
			pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject("Goblin");

			cout << "�÷��̾ ���������ϴ�.." << endl;
			system("pause");
			break;
		}
	}
}

