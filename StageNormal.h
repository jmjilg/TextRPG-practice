#pragma once

#include "Monster.h"

class CStageNormal
{
public:
	CStageNormal();
	~CStageNormal();

private:
	CMonster* pMonster;


public:
	void Init();
	void Run();
};

