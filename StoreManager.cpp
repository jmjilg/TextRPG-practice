#include "StoreManager.h"
#include "ObjectManager.h"
#include "Item.h"
#include "ItemWeapon.h"
#include "ItemArmor.h"
#include "Store.h"
#include "StoreWeapon.h"
#include "StoreArmor.h"

DEFINITION_SINGLE(CStoreManager)

CStoreManager::CStoreManager()
{
}

CStoreManager::~CStoreManager()
{
	Safe_Delete_VecList(m_vecStore);
}

bool CStoreManager::Init()
{
	CStore* pStore = CreateStore(STORE_MENU::WEAPON);
	pStore = CreateStore(STORE_MENU::ARMOR);

	//m_vecStore.push_back(new CStoreArmor);
	//m_vecStore.push_back(new CStoreWeapon);

	return true;
}

void CStoreManager::Run()
{
		CStore* pStore = NULL;

		int input = OutputMenu();

		if (input == (int)STORE_MENU::BACK)
			return;

		m_vecStore[input]->Run();

}

int CStoreManager::OutputMenu()
{
	while (true)
	{
		system("cls");
		cout << "1. 무기상점" << endl;
		cout << "2. 방어구상점" << endl;
		cout << "3. 뒤로가기" << endl;
		cout << "상점을 선택하세요 : ";

		int input = IntInput<int>();

		if (input <= (int)STORE_MENU::NONE || input > (int)STORE_MENU::BACK)
			continue;
		
		return input;
	}

}

CStore* CStoreManager::CreateStore(STORE_MENU eType)
{
	CStore* pStore = NULL;

	switch (eType)
	{
	case STORE_MENU::WEAPON:
		pStore = new CStoreWeapon;
		break;
	case STORE_MENU::ARMOR:
		pStore = new CStoreArmor;
		break;
	}

	return pStore;
}
