
#include "value.h"
#include "Stage.h"

CStage* CStage::m_pInst = NULL;

CStage::CStage()
{
}

CStage::~CStage()
{
	SAFE_DELETE(m_pInst)
}

void CStage::Init()
{
}

void CStage::Run()
{
}
