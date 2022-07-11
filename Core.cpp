
#include "Core.h"
#include "value.h"
#include "ObjectManager.h"
#include "StageManager.h"

DEFINITION_SINGLE(CCore)

CCore::CCore()
{
}

CCore::~CCore()
{
}

bool CCore::Init()
{
	if (!GET_SINGLE(CObjectManager)->Init())
		return false;

	if (!GET_SINGLE(CStageManager)->Init())
		return false;
}

void CCore::Run()
{

	switch (OutputMenu())
	{
	case (int)MAIN_MENU::MM_MAP:
		break;
	case (int)MAIN_MENU::MM_STORE:
		break;
	case (int)MAIN_MENU::MM_INVENTORY:
		break;
	case(int)MAIN_MENU::MM_INFO:
		break;
	case(int)MAIN_MENU::MM_END:
		return;
	}
	//cout << "�̸��� �Է��ϼ��� : ";
	//char name[NAME_LENGTH];
	//cin >> name;
	//cin.ignore();
	//while (true)
	//{
	//	system("cls");
	//	cout << "1. ����" << endl;
	//	cout << "2. �ü�" << endl;
	//	cout << "3. ������" << endl;
	//	cout << "������ �����ϼ���: ";
	//	int input = IntInput<int>() - 1;

	//	if (input < (int)JOB::WORRIAR || input >(int)JOB::WIZARD) {
	//		cin.ignore();
	//		continue;
	//	}

	//	CPlayer* pPlayer = new CPlayer;

	//	switch (input)
	//	{
	//	case (int)JOB::WORRIAR:
	//		pPlayer->Create(name, 5, 10, 10, 15, 200, 100, 0, 1);
	//		break;
	//	case (int)JOB::ARCHER:
	//		pPlayer->Create(name, 7, 12, 7, 12, 150, 150, 0, 1);
	//		break;
	//	case (int)JOB::WIZARD:
	//		pPlayer->Create(name, 10, 15, 5, 7, 100, 200, 0, 1);
	//		break;
	//	}
	//}
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

