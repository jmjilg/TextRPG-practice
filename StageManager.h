#pragma once

#include "value.h"

class CStageManager
{
	DECLARE_SINGLE(CStageManager)

public:
	void Init();
	void Run(class CPlayer* pPlayer);
};

