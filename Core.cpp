
#include "Core.h"
#include "value.h"
#include "ObjectManager.h"
#include "StageManager.h"
#include "StoreManager.h"

DEFINITION_SINGLE(CCore)

CCore::CCore()
{
}

CCore::~CCore()
{
	DESTROY_SINGLE(CObjectManager);
	DESTROY_SINGLE(CStageManager);
	DESTROY_SINGLE(CStoreManager);
}

bool CCore::Init()
{
	if (!GET_SINGLE(CObjectManager)->Init())
		return false;

	if (!GET_SINGLE(CStageManager)->Init())
		return false;

	if (!GET_SINGLE(CStoreManager)->Init())
		return false;
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
		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 인벤토리" << endl;
		cout << "4. 플레이어 정보" << endl;
		cout << "5. 종료" << endl;
		cout << "메인 메뉴를 선택하세요 : ";
		int input = IntInput<int>();

		if (input < 1 || input > 5)
			continue;

		return input;
	}
}

