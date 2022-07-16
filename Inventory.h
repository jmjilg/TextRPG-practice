#pragma once

#include "value.h"

class CInventory
{
	DECLARE_SINGLE(CInventory)

private:
	vector<class CItem*> m_vecItem;
	int m_iInvenMax;

public:
	bool Init();
	void Run();
	bool InventoryMax()
	{
		return m_vecItem.size() == m_iInvenMax;
	}
};

