#include "Inventory.h"
#include "ObjectManager.h"
#include "Player.h"

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
	CPlayer* pObj = (CPlayer*)GET_SINGLE(CObjectManager)->FindObject("Player");
	cout << "===================== Inventory =====================" << endl;
	pObj->Render();
	cout << "���� ���� : " << endl;
	cout << "���� �� : " << endl << endl;


}
