#include "Inventory.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Item.h"
#include "Obj.h"

DEFINITION_SINGLE(CInventory)

CInventory::CInventory() :
	m_iInvenMax(10)
{
}

CInventory::~CInventory()
{
}

bool CInventory::Init()
{
	return true;
}

void CInventory::Run()
{
	while (true)
	{
		system("cls");
		CPlayer* pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");
		cout << "===================== Inventory =====================" << endl;
		pPlayer->Render();
		Render();

		int input = IntInput<int>();

		if (input <= 0 || input > m_vecItem.size() + 1)
			continue;

		else if (input == m_vecItem.size())
			return;
		
		// 아무런 장착도 하지 않았을 경우
		CItem* pItem = pPlayer->Equip(m_vecItem[input-1]);

		if (!pItem)
		{
			vector<CItem*>::iterator iter = m_vecItem.begin() + (input - 1);
			m_vecItem.erase(iter);
		}
		// 장착 아이템이 있을 경우
		else
		{
			m_vecItem[input - 1] = pItem;
		}
	}

}

void CInventory::AddItem(CItem* pItem)
{
	m_vecItem.push_back(pItem);
}

void CInventory::Render()
{
	for (size_t i = 0; i < m_vecItem.size(); ++i)
	{
			cout << i + 1 << ". ";
			m_vecItem[i]->Render();
	}
	cout << m_vecItem.size() << ". 뒤로가기" << endl;
	cout << "장착할 아이템을 선택하시요 : ";
}

