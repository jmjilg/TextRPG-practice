#include "StageNormal.h"

CStageNormal::CStageNormal()
{
}

CStageNormal::~CStageNormal()
{
}

void CStageNormal::Init()
{
	CMonster* pMonster = new CMonster;
	pMonster->Create("Æ®·Ñ", 50, 75, 25, 50, 500, 250, 5000, 5, 10000);
}

void CStageNormal::Run()
{
}
