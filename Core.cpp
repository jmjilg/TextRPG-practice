
#include "Core.h"
#include "value.h"
#include "ObjectManager.h"
#include "StageManager.h"
#include "StoreManager.h"
#include "Inventory.h"

DEFINITION_SINGLE(CCore)

CCore::CCore()
{
}

CCore::~CCore()
{
	DESTROY_SINGLE(CObjectManager);
	DESTROY_SINGLE(CStageManager);
	DESTROY_SINGLE(CStoreManager);
	DESTROY_SINGLE(CInventory);
}

LEVELUPINFO CCore::GetLevelupInfo(JOB eJob)
{
	return m_tLevelupInfo[(int)eJob - 1]; // ���� �߻�
}

bool CCore::Init()
{
	SetLevelupInfo();

	if (!GET_SINGLE(CObjectManager)->Init())
		return false;

	if (!GET_SINGLE(CStageManager)->Init())
		return false;

	if (!GET_SINGLE(CStoreManager)->Init())
		return false;

	if (!GET_SINGLE(CInventory)->Init())
		return false;

	LEVELUPINFO _taglevelupInfo[(int)JOB::WIZARD];
}

void CCore::Run()
{
	while (true)
	{
		switch (OutputMenu())
		{
		case (int)MAIN_MENU::MM_MAP:
			GET_SINGLE(CStageManager)->Run();
			break;
		case (int)MAIN_MENU::MM_STORE:
			GET_SINGLE(CStoreManager)->Run();
			break;
		case (int)MAIN_MENU::MM_INVENTORY:
			GET_SINGLE(CInventory)->Run();
			break;
		case(int)MAIN_MENU::MM_INFO:
			break;
		case(int)MAIN_MENU::MM_END:
			return;
		}
	}
}

int CCore::OutputMenu()
{
	while (true)
	{
		system("cls");
		cout << "1. ��" << endl;
		cout << "2. ����" << endl;
		cout << "3. �κ��丮" << endl;
		cout << "4. �÷��̾� ����" << endl;
		cout << "5. ����" << endl;
		cout << "���� �޴��� �����ϼ��� : ";
		int input = IntInput<int>();

		if (input < 1 || input > 5)
			continue;

		return input;
	}
}

LEVELUPINFO CCore::CreateLevelupInfo(int iMinDamage, int iMaxDamage, int iMinArmor, int iMaxArmor, int iHP, int iMP)
{
	LEVELUPINFO temp;
	temp.iMinDamage = iMinDamage;
	temp.iMaxDamage = iMaxDamage;
	temp.iMinArmor = iMinArmor;
	temp.iMaxArmor = iMaxArmor;
	temp.iHP = iHP;
	temp.iMP = iMP;

	return temp;
}

void CCore::SetLevelupInfo()
{
	m_tLevelupInfo[(int)JOB::WORRIAR - 1] = CreateLevelupInfo(5, 10, 15, 20, 100, 10);
	m_tLevelupInfo[(int)JOB::ARCHER - 1] = CreateLevelupInfo(10, 15, 10, 15, 80, 30);
	m_tLevelupInfo[(int)JOB::WIZARD - 1] = CreateLevelupInfo(15, 20, 5, 10, 50, 50);
}

