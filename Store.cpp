#include "Store.h"
#include "Item.h"
#include "ItemWeapon.h"
#include "ItemArmor.h"

CStore::CStore()
{
}

CStore::~CStore()
{
	Safe_Delete_VecList(m_vecItem);
}

bool CStore::Init()
{
	return true;
}

CItem* CStore::CreateItem(const char* pName, ITEM_TYPE eType, int iPrice, int iSell, const char* pDesc)
{
	CItem* pItem = NULL;

	switch (eType)
	{
	case ITEM_TYPE::WEAPON:
		pItem = new CItemWeapon;
		break;
	case ITEM_TYPE::ARMOR:
		pItem = new CItemArmor;
		break;
	}

	pItem->SetName(pName);
	pItem->SetItemInfo(eType, iPrice, iSell, pDesc);

	if (!pItem->Init())
	{
		SAFE_DELETE(pItem);
		return NULL;
	}

	m_vecItem.push_back(pItem);

	return pItem;
}
