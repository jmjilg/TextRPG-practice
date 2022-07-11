#pragma once

#include "Monster.h"
#include "Player.h"
#include "Stage.h"

class CStageNormal :
	public CStage
{
public:
	CStageNormal();
	~CStageNormal();

private:
	class CMonster* m_pMonster;


public:
	virtual bool Init();
	virtual void Run();
};

