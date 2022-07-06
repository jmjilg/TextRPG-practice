
#include "Core.h"
#include "value.h"
#include "StageManager.h"
#include "Character.h"
#include "Player.h"
#include "Monster.h"
#include "StageEasy.h"

CCore* CCore::m_pInst = NULL;

CCore::CCore()
{
}

CCore::~CCore()
{
	SAFE_DELETE(m_pInst)
}

void CCore::Init()
{
}

void CCore::Run()
{
	while (true)
	{
		cout << "이름을 입력하세요 : ";
		char name[NAME_LENGTH];
		cin >> name;
		cin.ignore();

		system("cls");
		cout << "1. 전사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요: ";
		int input = IntInput<int>()-1;

		if (input < (int)JOB::WORRIAR || input >(int)JOB::WIZARD) {
			cin.ignore();
			continue;
		}

		CPlayer* p_player = new CPlayer;

		switch (input)
		{
		case (int)JOB::WORRIAR:
			p_player->Create(name, 5, 10, 10, 15, 200, 100, 0, 1);
			break;
		case (int)JOB::ARCHER:
			p_player->Create(name, 7, 12, 7, 12, 150, 150, 0, 1);
			break;
		case (int)JOB::WIZARD:
			p_player->Create(name, 10, 15, 5, 7, 100, 200, 0, 1);
			break;
		}

		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 인벤토리" << endl;
		cout << "4. 플레이어 정보" << endl;
		cout << "5. 종료" << endl;
		cout << "메인 메뉴를 선택하세요 : ";
		input = IntInput<int>();

		switch (input)
		{
		case MM_MAP:
		{
			system("cls");
			CStageEasy* CEasy = new CStageEasy;
			CEasy->Init();
			CEasy->Run();
			system("pause");
			break;
		}
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		case MM_INFO:
			break;
		case MM_END:
			return;
		}
	}
}
