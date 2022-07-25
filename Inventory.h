#pragma once

#include "value.h"

class CItem;
class CInventory
{
	DECLARE_SINGLE(CInventory)

private:
	vector<CItem*> m_vecItem;
	int m_iInvenMax;
	friend class CPlayer;

public:
	bool Init();
	void Run();
	bool InventoryMax()
	{
		return m_vecItem.size() == m_iInvenMax;
	}
	void AddItem(CItem* pItem);
	void Render();
};

