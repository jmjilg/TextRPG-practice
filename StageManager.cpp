
#include "StageManager.h"
#include "value.h"
#include "StageEasy.h"
#include "StageNormal.h"
#include "StageHard.h"

DEFINITION_SINGLE(CStageManager)

CStageManager::CStageManager()
{
}

CStageManager::~CStageManager()
{
	SAFE_DELETE(m_pInst)
}

void CStageManager::Init()
{
}

void CStageManager::Run(class CPlayer* pPlayer)
{
	while (true)
	{
		system("cls");
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. �����" << endl;
		cout << "���̵��� �����ϼ��� :";
		int input = IntInput<int>();
		switch (input)
		{
		case (int)STAGE_LEVEL::EASY:
		{
			CStageEasy* CEasy = new CStageEasy;
			CEasy->Init();
			CEasy->Run(pPlayer);
			break;
		}
		case (int)STAGE_LEVEL::NORMAL:
		{
			CStageNormal* CNormal = new CStageNormal;
			CNormal->Init();
			CNormal->Run(pPlayer);
			break;
		}
		case (int)STAGE_LEVEL::HARD:
		{
			CStageHard* CHard = new CStageHard;
			CHard->Init();
			CHard->Run(pPlayer);
			break;
		}
		}

	}
}
