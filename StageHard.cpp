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
	pMonster->SetCharacterInfo("�巡��", 100, 150, 50, 70, 1000, 500, 10000, 10, 30000);
}

void CStageHard::Run(CPlayer* pPlayer)
{
	while (true)
	{
		system("cls");
		m_pMonster->Render();
		pPlayer->Render();
		cout << "1. ����" << endl;
		cout << "2. ��������" << endl;
		cout << "�ൿ�� �����ϼ��� : ";
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
	// �÷��̾ ���� ����
	int iDamage = rand() % (pPlayer->m_pInfo->iMaxDamage - pPlayer->m_pInfo->iMinDamage + 1) +
		pPlayer->m_pInfo->iMinDamage;
	int iArmor = rand() % (pMonster->m_pInfo->iMaxArmor - pMonster->m_pInfo->iMinDamage + 1) +
		pMonster->m_pInfo->iMinArmor;

	iDamage = iDamage <= iArmor ? 1 : iDamage - iArmor;

	pMonster->m_pInfo->iHP -= iDamage;

	// �÷��̾ ���� �����߷��� ��
	if (pMonster->m_pInfo->iHP <= 0)
	{
		// ��� ȹ��
		pPlayer->iGold += pMonster->iGold;

		// ����ġ ȹ��
		pPlayer->m_pInfo->iExp += pMonster->m_pInfo->iExp;

		// ���� �ʱ�ȭ
		pMonster->m_pInfo->iHP = pMonster->m_pInfo->iHPmax;

		cout << "����� ��ġ����!" << endl;
		system("pause");

		return;
	}

	// ���Ͱ� �÷��̾� ����
	iDamage = rand() % (pMonster->m_pInfo->iMaxDamage - pMonster->m_pInfo->iMinDamage + 1) +
		pMonster->m_pInfo->iMinDamage;
	iArmor = rand() % (pPlayer->m_pInfo->iMaxArmor - pPlayer->m_pInfo->iMinDamage + 1) +
		pPlayer->m_pInfo->iMinArmor;

	iDamage = iDamage <= iArmor ? 1 : iDamage - iArmor;

	pPlayer->m_pInfo->iHP -= iDamage;

	// �÷��̾ ���Ϳ��� �й����� ��
	if (pPlayer->m_pInfo->iHP <= 0)
	{
		// ��� 10% ���
		pPlayer->iGold *= 0.9f;

		// ����ġ 10% ���
		pPlayer->m_pInfo->iExp *= 0.9f;

		// �÷��̾� �ʱ�ȭ
		pPlayer->m_pInfo->iHP = pPlayer->m_pInfo->iHPmax;

		cout << "�÷��̾ ���������ϴ�.." << endl;
		system("pause");

		return;
	}
}
