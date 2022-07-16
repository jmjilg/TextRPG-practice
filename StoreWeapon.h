#pragma once

#include "value.h"
#include "Store.h"

class CStoreWeapon	:
	public CStore
{
public:
	CStoreWeapon();
	virtual ~CStoreWeapon();

public:
	bool Init();
	virtual void Run();
	virtual int OutputMenu();
};

