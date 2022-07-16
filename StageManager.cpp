
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
	Safe_Delete_VecList(m_vecStage);
}

bool CStageManager::Init()
{
	CreateStage(STAGE_LEVEL::EASY);
	CreateStage(STAGE_LEVEL::NORMAL);
	CreateStage(STAGE_LEVEL::HARD);

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
		cout << "4. �ڷΰ���" << endl;
		cout << "���̵��� �����ϼ��� :";

		input = IntInput<int>();

		if (input <= (int)STAGE_LEVEL::NONE || input > (int)STAGE_LEVEL::BACK)
			continue;

		if (input == (int)STAGE_LEVEL::BACK)
			return;
		
		m_vecStage[input-1]->Run();

	}
}

bool CStageManager::CreateStage(STAGE_LEVEL eType)
{
	CStage* pStage = NULL;

	switch (eType)
	{
	case STAGE_LEVEL::EASY:
		pStage = new CStageEasy;
		break;
	case STAGE_LEVEL::NORMAL:
		pStage = new CStageNormal;
		break;
	case STAGE_LEVEL::HARD:
		pStage = new CStageHard;
		break;
	}

	if (!pStage->Init())
	{
		SAFE_DELETE(pStage)
			return false;
	}

	m_vecStage.push_back(pStage);

	return true;
}

