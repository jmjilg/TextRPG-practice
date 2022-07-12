
#include "StageManager.h"
#include "value.h"
#include "Stage.h"
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

bool CStageManager::Init()
{
	return true;
}

void CStageManager::Run()
{

	int input;

	while (true)
	{
		system("cls");
		cout << "1. 쉬움" << endl;
		cout << "2. 보통" << endl;
		cout << "3. 어려움" << endl;
		cout << "4. 뒤로가기" << endl;
		cout << "난이도를 선택하세요 :";

		input = IntInput<int>();

		if (input <= (int)STAGE_LEVEL::NONE || input > (int)STAGE_LEVEL::BACK)
			continue;

		CStage* pStage = NULL;

		switch (input)
		{
		case (int)STAGE_LEVEL::EASY:
			pStage = new CStageEasy;
			break;
		case (int)STAGE_LEVEL::NORMAL:
			pStage = new CStageNormal;
			break;
		case (int)STAGE_LEVEL::HARD:
			pStage = new CStageHard;
			break;
		case (int)STAGE_LEVEL::BACK:
			return;
		}

		pStage->Init();
		pStage->Run();
	}
}

