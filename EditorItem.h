#pragma once

#include "value.h"

class CEditorItem
{
private:
	vector<class CItem*> m_vecWeapon;
	vector<class CItem*> m_vecArmor;

public:
	bool Init();
	void Run();	
	void Insert();
	int InsertMenu();
	int OutputMenu();
	void OutputList();
	void Save();
	void Load();

	DECLARE_SINGLE(CEditorItem)
};

