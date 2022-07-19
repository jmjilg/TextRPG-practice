#include "StoreArmor.h"
#include "ItemArmor.h"
#include "Item.h"
#include "ObjectManager.h"
#include "Character.h"
#include "Obj.h"
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

	pArmor = (CItemArmor*)CreateItem("õ����", ITEM_TYPE::ARMOR, 1000, 500, "õ���� ���� ����");
	pArmor->SetArmorInfo(5, 10);

	pArmor = (CItemArmor*)CreateItem("���ð���", ITEM_TYPE::ARMOR, 3000, 1500, "���ð� ���� ����");
	pArmor->SetArmorInfo(15, 25);

	pArmor = (CItemArmor*)CreateItem("��ȣõ��", ITEM_TYPE::ARMOR, 10000, 5000, "õ���� ���� ����");
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

int CStoreArmor::OutputMenu()
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

		CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");
		cout << "�����ݾ� :" << pPlayer->GetGold()<< endl;

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
