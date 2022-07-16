#pragma once

#include "value.h"

class CStageManager
{
	DECLARE_SINGLE(CStageManager)

private:
	vector<class CStage*> m_vecStage;
	
public:
	bool Init();
	void Run();
	bool CreateStage(STAGE_LEVEL eType);
};

