#pragma once

#include "value.h"

class CItem;

class CStore
{
protected:
	CStore();
public:
	virtual ~CStore();

private:
	friend class CStoreManager;

protected:
	ITEM_TYPE OT;
	vector<CItem*> m_vecItem;

public:
	virtual bool Init() = 0;
	virtual void Run() = 0;
	virtual int OutputMenu() = 0;
	ITEM_TYPE GetItemType()	const
	{
		return OT;
	}
	CItem* CreateItem(const char* pName, ITEM_TYPE eType, int iPrice,
		int iSell, const char* pDesc);
};

