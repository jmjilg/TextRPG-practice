#pragma once

#include "value.h"

class CObj;
class CObjectManager
{
	DECLARE_SINGLE(CObjectManager)

private:
	unordered_map<string, CObj*> m_mapObj;

public:
	bool Init();
	CObj* CreateObject(const string& strKey, OBJECT_TYPE eType);
	CObj* FindObject(const string& strKey);
	CObj* CloneObject(const string& strKey);
	CObj* CloneObject(STAGE_LEVEL eType);
};

