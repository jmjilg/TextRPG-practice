#pragma once

#include "Store.h"

class CStoreArmor	:
	public CStore
{
public:
	CStoreArmor();
	virtual ~CStoreArmor();

public:
	bool Init();
	virtual void Run();
	virtual int OutputMenu();
	void Buy();
	void LackMoney();
};

