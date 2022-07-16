#include "StoreWeapon.h"
#include "ObjectManager.h"
#include "ItemWeapon.h"
#include "Item.h"

CStoreWeapon::CStoreWeapon()
{
}

CStoreWeapon::~CStoreWeapon()
{
}

bool CStoreWeapon::Init()
{

	CItemWeapon* pWeapon;

	pWeapon = (CItemWeapon*)CreateItem("목검", ITEM_TYPE::WEAPON, 1000, 500, "나무로 만든 검");
	pWeapon->SetWeaponInfo(10, 15, 10);

	pWeapon = (CItemWeapon*)CreateItem("철검", ITEM_TYPE::WEAPON, 3000, 1500, "철로 만든 검");
	pWeapon->SetWeaponInfo(30, 45, 20);
	
	pWeapon = (CItemWeapon*)CreateItem("무한의 대검", ITEM_TYPE::WEAPON, 10000, 5000, "무한의 대검");
	pWeapon->SetWeaponInfo(50, 70, 30);

	return true;
}

void CStoreWeapon::Run()
{
}

int CStoreWeapon::OutputMenu()
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
