#include "StageHard.h"
#include "ObjectManager.h"
#include "Monster.h"
#include "Player.h"

CStageHard::CStageHard()
{
}

CStageHard::~CStageHard()
{
}

bool CStageHard::Init()
{
	return true;
}

void CStageHard::Run()
{
	CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");
	CMonster* pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject(STAGE_LEVEL::HARD);


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
			pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject(STAGE_LEVEL::HARD);

			cout <<pMonster->GetName() << "�� ��ġ����!" << endl;

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
			pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CloneObject(STAGE_LEVEL::HARD);

			cout << "�÷��̾ ���������ϴ�.." << endl;
			system("pause");
			break;
		}
	}
}
