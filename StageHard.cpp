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
	pMonster->Create("�巡��", 100, 150, 50, 70, 1000, 500, 10000, 10, 30000);
}

void CStageHard::Run()
{
}
