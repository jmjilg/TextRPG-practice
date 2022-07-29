#pragma once

#include "value.h"

class CEditorMonster
{
private:
	vector<class CMonster*> m_vecMonster;

public:
	bool Init();
	void Run();
	void Insert();
	int OutputMenu();
	void OutputList();
	void Save();
	void Load();

	DECLARE_SINGLE(CEditorMonster)
};

