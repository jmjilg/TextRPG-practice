#include "StoreWeapon.h"
#include "ObjectManager.h"
#include "ItemWeapon.h"
#include "Item.h"
#include "Player.h"
#include "Inventory.h"
#include "FileStream.h"

CStoreWeapon::CStoreWeapon()
{
}

CStoreWeapon::~CStoreWeapon()
{
}

bool CStoreWeapon::Init()
{

	CItemWeapon* pWeapon = NULL;

	CFileStream file("StoreWeapon.swp", "rb");

	if (file.GetOpen())
	{
		int iWeaponCount = 0;
		file.Read(&iWeaponCount, 4);

		for (size_t i = 0; i < iWeaponCount; ++i)
		{
			pWeapon = new CItemWeapon;

			pWeapon->Load(&file);

			m_vecItem.push_back(pWeapon);
		}
	}

	else
	{
		pWeapon = (CItemWeapon*)CreateItem("���", ITEM_TYPE::WEAPON, 1000, 500, "������ ���� ��");
		pWeapon->SetWeaponInfo(10, 15, 10);

		pWeapon = (CItemWeapon*)CreateItem("ö��", ITEM_TYPE::WEAPON, 3000, 1500, "ö�� ���� ��");
		pWeapon->SetWeaponInfo(30, 45, 20);

		pWeapon = (CItemWeapon*)CreateItem("������ ���", ITEM_TYPE::WEAPON, 10000, 5000, "������ ���");
		pWeapon->SetWeaponInfo(50, 70, 30);
	}

	return true;
}

void CStoreWeapon::Run()
{
	CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");

	while (true)
	{

		int input = OutputMenu();
		if (input == WEAPON_COUNT + 1)
			return;

		if (pPlayer->GetGold() < m_vecItem[input - 1]->GetPrice())
		{
			cout << "�ݾ��� �����մϴ�." << endl;
			system("pause");
			continue;
		}

		else if (GET_SINGLE(CInventory)->InventoryMax())
		{
			cout << "������ �����մϴ�" << endl;
			system("pause");
			continue;
		}


		pPlayer->SetGold(-m_vecItem[input - 1]->GetPrice());

		CItem* pItem = (CItem*)m_vecItem[input - 1]->Clone();

		GET_SINGLE(CInventory)->AddItem(pItem);
	}
}

int CStoreWeapon::OutputMenu()
{
	while (true)
	{
		system("cls");
		cout << "====================== ���� ���� ======================" << endl;
		for (int i = 0; i < ARMOR_COUNT; ++i)
		{
			cout << i + 1 << ". ";
			m_vecItem[i]->Render();
			cout << endl;
		}
		cout << "4. �ڷΰ���" << endl;

		CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");
		cout << "�����ݾ� :" << pPlayer->GetGold() << endl;

		int input = IntInput<int>();

		if (input <= 0 || input > 4)
			continue;

		return input;
	}
}
