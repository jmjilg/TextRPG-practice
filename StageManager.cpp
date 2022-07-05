
#include "StageManager.h"
#include "value.h"

CStageManager* CStageManager::m_pInst = NULL;

CStageManager::CStageManager()
{
}

CStageManager::~CStageManager()
{
	SAFE_DELETE(m_pInst)
}
