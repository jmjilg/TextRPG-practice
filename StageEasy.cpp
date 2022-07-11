#include "StageEasy.h"
#include "Monster.h"
#include "Player.h"
#include "ObjectManager.h"
#include "value.h"

CStageEasy::CStageEasy()
{
}

CStageEasy::~CStageEasy()
{
}

bool CStageEasy::Init()
{
	return true;
}

void CStageEasy::Run()
{
	GET_SINGLE(CObjectManager)->FindObject("플레이어");
}

