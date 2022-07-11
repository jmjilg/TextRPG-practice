
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

	iDamage = iDamage <= iArmor ? 1 : iDamage - iArmor;

	
	

	// �÷��̾ ���� �����߷��� ��
	if (pMonster->Die(iDamage))
	{
		return BATTLE_FLAG::PLAYER_WIN;
		
		//// ��� ȹ��
		//pPlayer->iGold += pMonster->iGold;

		//// ����ġ ȹ��
		//pPlayer->m_pInfo->iExp += pMonster->m_pInfo->iExp;

		//// ���� �ʱ�ȭ
		//pMonster->m_pInfo->iHP = pMonster->m_pInfo->iHPmax;

		//cout << "����� ��ġ����!" << endl;
		//system("pause");

		//return;
	}

	// ���Ͱ� �÷��̾� ����
	iDamage = pMonster->GetDamage();
	iArmor = pPlayer->GetArmor();

	iDamage = iDamage <= iArmor ? 1 : iDamage - iArmor;


	// �÷��̾ ���Ϳ��� �й����� ��
	if (pPlayer->Die(iDamage))
	{

		return BATTLE_FLAG::PLAYER_DIE;
		//// ��� 10% ���
		//pPlayer->iGold *= 0.9f;

		//// ����ġ 10% ���
		//pPlayer->m_pInfo->iExp *= 0.9f;

		//// �÷��̾� �ʱ�ȭ
		//pPlayer->m_pInfo->iHP = pPlayer->m_pInfo->iHPmax;

		//cout << "�÷��̾ ���������ϴ�.." << endl;
		//system("pause");

		//return;
	}
}

