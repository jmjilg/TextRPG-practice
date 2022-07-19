#pragma once

#include "Item.h"

class CItemArmor	:
	public CItem
{
private:
	CItemArmor();

public:
	~CItemArmor();

private:
	friend class CObjectManager;
	friend class CStore;
	friend class CStoreArmor;
	friend class CStoreManager;

private:
	int m_iArmorMin;
	int m_iArmorMax;

public:
	virtual void Render();
	virtual CItem* Clone();
	OBJECT_TYPE GetObjectType()
	{
		return OBJECT_TYPE::MONSTER;
	}
	void SetArmorInfo(int iArmorMin, int iArmorMax)
	{
		m_iArmorMin = iArmorMin;
		m_iArmorMax = iArmorMax;
	}
};

