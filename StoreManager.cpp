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
	pStore->Init();
	m_vecStore.push_back(pStore);
	
	pStore = CreateStore(STORE_MENU::ARMOR);
	pStore->Init();
	m_vecStore.push_back(pStore);

	return true;
}

void CStoreManager::Run()
{
	while (true)
	{
		CStore* pStore = NULL;

		int input = OutputMenu();

		if (input <= (int)STORE_MENU::NONE || input >(int)STORE_MENU::BACK)
			continue;

		if (input == (int)STORE_MENU::BACK)
			return;

		m_vecStore[input - 1]->Run();
	}
}

int CStoreManager::OutputMenu()
{
	while (true)
	{
		system("cls");
		cout << "1. �������" << endl;
		cout << "2. ������" << endl;
		cout << "3. �ڷΰ���" << endl;
		cout << "������ �����ϼ��� : ";

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
