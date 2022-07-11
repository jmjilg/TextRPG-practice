#pragma once

#include"Stage.h"

class CStageHard :
	public CStage
{
public:
	CStageHard();
	~CStageHard();

private:
	class CMonster* m_pMonster;


public:
	virtual bool Init();
	virtual void Run();
};

