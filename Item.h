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
	friend class CEditorItem;

protected:
	ITEMINFO	m_tInfo;

public:
	bool Init();
	virtual void Render() = 0;
	virtual CObj* Clone() = 0;
	ITEM_TYPE GetItemType()
	{
		return m_tInfo.eType;
	}
	int GetPrice()	const
	{
		return m_tInfo.iPrice;
	}
	void SetItemInfo(ITEM_TYPE eType, int iPrice, int iSell, const char* pDesc);
	virtual void Save(class CFileStream* pFile);
	virtual void Load(class CFileStream* pFile);
};

