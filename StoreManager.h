#pragma once

#include "value.h"

class CStore;
class CStoreManager
{
	DECLARE_SINGLE(CStoreManager)

private:
	vector<CStore*> m_vecStore;

public:
	bool Init();
	void Run();
	int OutputMenu();
	CStore* CreateStore(STORE_MENU eType);
};

