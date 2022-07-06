#include "StageEasy.h"
#include "Player.h"

CStageEasy::CStageEasy()
{
}

CStageEasy::~CStageEasy()
{
	delete pMonster;
}

void CStageEasy::Init()
{
	pMonster = new CMonster;
	pMonster->Create("°íºí¸°", 5, 10, 5, 10, 50, 0, 100, 1, 1000);
}

void CStageEasy::Run()
{
	pMonster->Info();
}
