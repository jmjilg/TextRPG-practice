
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
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. �����" << endl;
		cout << "���̵��� �����ϼ��� :";

		input = IntInput<int>();

		if (input < (int)STAGE_LEVEL::EASY || input >(int)STAGE_LEVEL::HARD)
			continue;
	}

	CStage* pStage;

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
	}

	pStage->Init();
	pStage->Run();
}

