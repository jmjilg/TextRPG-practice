#pragma once

#include "Monster.h"

class CStageEasy
{
public:
	CStageEasy();
	~CStageEasy();

private:
	CMonster* pMonster;

public:
	void Init();
	void Run();
};

