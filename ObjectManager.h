#pragma once

#include "value.h"

class CObjectManager
{
	DECLARE_SINGLE(CObjectManager)

private:
	static CObjectManager* m_pInst;
	unordered_map<string, class CObj*> m_mapObj;

public:
	bool Init();
	CObj* CreateObject(const string& strKey, OBJECT_TYPE eType);
	CObj* FindObject(const string& strKey);
	CObj* CloneObject(const string& strKey);
	//CObj* CloneObject(OBJECT_TYPE eType); ¹Ì±¸Çö
};

