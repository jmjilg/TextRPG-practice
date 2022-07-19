#pragma once

#include "value.h"
#include "Obj.h"

class CItem	:
	public CObj
{
protected:
	CItem();
	CItem(const CItem& item);

public:
	virtual ~CItem();

private:
	friend class CObjectManager;

protected:
	ITEMINFO	m_tInfo;

public:
	bool Init();
	virtual void Render() = 0;
	ITEM_TYPE GetItemType()
	{
		return m_tInfo.eType;
	}
	OBJECT_TYPE GetObjectType()
	{
		return OBJECT_TYPE::MONSTER;
	}
	int GetPrice()	const
	{
		return m_tInfo.iPrice;
	}
	void SetItemInfo(ITEM_TYPE eType, int iPrice, int iSell, const char* pDesc);
};

