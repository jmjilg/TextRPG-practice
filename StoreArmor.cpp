#include "StoreArmor.h"
#include "ItemArmor.h"
#include "ObjectManager.h"
#include "Character.h"
#include "Player.h"
#include "Inventory.h"

CStoreArmor::CStoreArmor()	
{
	OT = ITEM_TYPE::ARMOR;
}

CStoreArmor::~CStoreArmor()
{
}

bool CStoreArmor::Init()
{
	CItemArmor* pArmor;

	pArmor = (CItemArmor*)CreateItem("천갑옷", ITEM_TYPE::ARMOR, 1000, 500, "천으로 만든 갑옷");
	pArmor->SetArmorInfo(5, 10);

	pArmor = (CItemArmor*)CreateItem("가시갑옷", ITEM_TYPE::ARMOR, 3000, 1500, "가시가 박힌 갑옷");
	pArmor->SetArmorInfo(15, 25);

	pArmor = (CItemArmor*)CreateItem("수호천사", ITEM_TYPE::ARMOR, 10000, 5000, "천으로 만든 갑옷");
	pArmor->SetArmorInfo(35, 50);

	return true;
}

void CStoreArmor::Run()
{
	CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");

	while (true)
	{
		int input = OutputMenu();
		if (input == ARMOR_COUNT + 1)
			return;

		if (pPlayer->GetGold() < m_vecItem[input - 1]->GetPrice())
		{
			cout << "금액이 부족합니다." << endl;
			continue;
		}

		else if (GET_SINGLE(CInventory)->InventoryMax())
		{
			cout << "공간이 부족합니다" << endl;
			continue;
		}


	}
}

int CStoreArmor::OutputMenu()
{
	while (true)
	{
		system("cls");
		cout << "====================== 방어구상점 ======================" << endl;
		for (int i = 0; i < ARMOR_COUNT; ++i)
		{
			cout << i + 1 << ". ";
			m_vecItem[i]->Render();
			cout << endl;
		}

		cout << "4. 뒤로가기" << endl;
		cout << "보유금액 :" << endl;

		int input = IntInput<int>();

		if (input <= 0 || input > 4)
			continue;

		return input;
	}
}

void CStoreArmor::Buy()
{
}

void CStoreArmor::LackMoney()
{
}
