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

	pWeapon = (CItemWeapon*)CreateItem("���", ITEM_TYPE::WEAPON, 1000, 500, "������ ���� ��");
	pWeapon->SetWeaponInfo(10, 15, 10);

	pWeapon = (CItemWeapon*)CreateItem("ö��", ITEM_TYPE::WEAPON, 3000, 1500, "ö�� ���� ��");
	pWeapon->SetWeaponInfo(30, 45, 20);
	
	pWeapon = (CItemWeapon*)CreateItem("������ ���", ITEM_TYPE::WEAPON, 10000, 5000, "������ ���");
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
		cout << "====================== ������ ======================" << endl;
		for (int i = 0; i < ARMOR_COUNT; ++i)
		{
			cout << i + 1 << ". ";
			m_vecItem[i]->Render();
			cout << endl;
		}

		cout << "4. �ڷΰ���" << endl;
		cout << "�����ݾ� :" << endl;

		int input = IntInput<int>();

		if (input <= 0 || input > 4)
			continue;

		return input;
	}
}
