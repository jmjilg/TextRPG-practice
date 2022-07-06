#pragma once

#include "Monster.h"

class CStageHard
{
public:
	CStageHard();
	~CStageHard();

private:
	CMonster* pMonster;


public:
	void Init();
	void Run();
};

