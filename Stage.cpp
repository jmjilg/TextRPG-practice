
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

void CStage::OutputStageName(const char* pName)
{
	cout << "========================	" << pName << " ========================" << endl;
}

int CStage::OutputMenu()
{
	while (true)
	{
		cout << "1. ����" << endl;
		cout << "2. ��������" << endl;
		cout << "�ൿ�� �����ϼ��� : ";
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

	// ������ ������ �÷��̾��� ���ݷ� ���� ���� �� �������� 1�� ��
	iDamage = iDamage <= iArmor ? 1 : iDamage - iArmor;	

	// �÷��̾ ���� �����߷��� ��
	if (pMonster->Die(iDamage))
		return BATTLE_FLAG::PLAYER_WIN;

	// ���Ͱ� �÷��̾� ����
	iDamage = pMonster->GetDamage();
	iArmor = pPlayer->GetArmor();

	iDamage = iDamage <= iArmor ? 1 : iDamage - iArmor;


	// �÷��̾ ���Ϳ��� �й����� ��
	if (pPlayer->Die(iDamage))
		return BATTLE_FLAG::PLAYER_DIE;
}

