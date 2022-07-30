#include "EditorItem.h"
#include "FileStream.h"
#include "ItemWeapon.h"
#include "ItemArmor.h"

DEFINITION_SINGLE(CEditorItem)

enum class EDITOR_MENU
{
	NONE,
	INSERT,
	MODIFY,
	DELETE,
	OUTPUT,
	SAVE,
	LOAD,
	BACK
};

enum class InsertMenu
{
	NONE,
	WEAPON,
	ARMOR
};

CEditorItem::CEditorItem()
{
}

CEditorItem::~CEditorItem()
{
	Safe_Delete_VecList(m_vecWeapon);
	Safe_Delete_VecList(m_vecArmor);
}

bool CEditorItem::Init()
{
	return true;
}

void CEditorItem::Run()
{
	while (true)
	{
		switch (OutputMenu())
		{
		case (int)EDITOR_MENU::INSERT:
			Insert();
			break;
		case (int)EDITOR_MENU::MODIFY:
			break;
		case (int)EDITOR_MENU::DELETE:
			break;
		case (int)EDITOR_MENU::OUTPUT:
			OutputList();
			break;
		case (int)EDITOR_MENU::SAVE:
			Save();
			break;
		case (int)EDITOR_MENU::LOAD:
			Load();
			break;
		case (int)EDITOR_MENU::BACK:
			return;
		}
	}
}

void CEditorItem::Insert()
{
	CItem* pItem = NULL;
	ITEM_TYPE eType;

	switch (InsertMenu())
	{
	case (int)InsertMenu::WEAPON:
		pItem = new CItemWeapon;
		eType = ITEM_TYPE::WEAPON;
		break;
	case(int)InsertMenu::ARMOR:
		pItem = new CItemArmor;
		eType = ITEM_TYPE::ARMOR;
		break;
	}

	if (!pItem->Init())
	{
		SAFE_DELETE(pItem);
		return;
	}

	char pName[NAME_LENGTH] = {};

	string strTypeName;
	int iPrice;
	int iSell;
	char pDesc[STR_DESC_LENGTH] = {};

	cin.ignore(1024, '\n');
	system("cls");
	cout << "�̸��� �Է��ϼ��� : ";
	cin.getline(pName, NAME_LENGTH);

	cout << "���� :";
	cin >> iPrice;

	cout << "�Ǹ� ���� :";
	cin >> iSell;

	cin.ignore(1024, '\n');
	cout << "������ ���� :";
	cin.getline(pDesc, STR_DESC_LENGTH - 1);

	pItem->SetName(pName);
	pItem->SetItemInfo(eType, iPrice, iSell, pDesc);

	switch (eType)
	{
	case ITEM_TYPE::WEAPON:
	{
		int iAttackMin;
		int iAttackMax;
		float fCritical;
		cout << "�ּ� ���ݷ� :";
		cin >> iAttackMin;
		
		cout << "�ִ� ���ݷ� :";
		cin >> iAttackMax;

		cout << "ġ��Ÿ Ȯ�� :";
		cin >> fCritical;

		((CItemWeapon*)pItem)->SetWeaponInfo(iAttackMin, iAttackMax, fCritical);

		m_vecWeapon.push_back(pItem);
		break;
	}
	case ITEM_TYPE::ARMOR:
	{
		int iArmorMin;
		int iArmorMax;

		cout << "�ּ� ���� :";
		cin >> iArmorMin;

		cout << "�ִ� ���� :";
		cin >> iArmorMax;

		((CItemArmor*)pItem)->SetArmorInfo(iArmorMin, iArmorMax);
		m_vecArmor.push_back(pItem);
		break;
	}
	}


}

int CEditorItem::InsertMenu()
{
	while (true)
	{
		system("cls");
		cout << "1. ����" << endl;
		cout << "2. ��" << endl;
		cout << "�޴��� �����ϼ���.";
		int input = IntInput<int>();

		if (input <= (int)InsertMenu::NONE || input > (int)InsertMenu::ARMOR)
			continue;
		
		return input;
	}
}

int CEditorItem::OutputMenu()
{
	int input;

	while (true)
	{
		system("cls");
		cout << "1. ������ �߰�" << endl;
		cout << "2. ������ ����" << endl;
		cout << "3. ������ ����" << endl;
		cout << "4. ������ ���" << endl;
		cout << "5. ����" << endl;
		cout << "6. �ҷ�����" << endl;
		cout << "7. �ڷΰ���" << endl;
		cout << "�޴��� �����ϼ��� : ";

		input = IntInput<int>();
		if (input <= (int)EDITOR_MENU::NONE || input > (int)EDITOR_MENU::BACK)
			continue;

		return input;
	}
}

void CEditorItem::OutputList()
{
	system("cls");
	cout << "================= ���� ���� =================" << endl;
	for (size_t i = 0; i < m_vecWeapon.size(); ++i)
	{
		cout << i + 1 << "." << endl;
		m_vecWeapon[i]->Render();
	}


	cout << "================= �� ���� =================" << endl;
	for (size_t i = 0; i < m_vecArmor.size(); ++i)
	{
		cout << i + 1 << "." << endl;
		m_vecArmor[i]->Render();
	}
	system("pause");
}

void CEditorItem::Save()
{
	system("cls");
	cout << "================= ���� ���� =================" << endl;

	CFileStream file("StoreWeapon.swp", "wb");

	if (file.GetOpen())
	{
		size_t iWeaponCount = m_vecWeapon.size();

		file.Write(&iWeaponCount, 4);

		for (size_t i = 0; i < iWeaponCount; ++i)
		{
			m_vecWeapon[i]->Save(&file);
		}

		file.Close();
	}

	file.Open("StoreArmor.sar", "wb");

	if(file.GetOpen())
	{
		size_t iArmorCount = m_vecArmor.size();

		file.Write(&iArmorCount, 4);

		for (size_t i = 0; i < iArmorCount; ++i)
		{
			m_vecArmor[i]->Save(&file);
		}

		file.Close();
	}

	cout << "���� ���� �Ϸ�" << endl;
	system("pause");

}

void CEditorItem::Load()
{
	system("cls");
	cout << "================= ���� �ҷ����� =================" << endl;

	CFileStream file("StoreWeapon.swp", "rb");

	if (file.GetOpen())
	{
		size_t iWeaponCount = 0;

		file.Read(&iWeaponCount, 4);

		for (size_t i = 0; i < iWeaponCount; ++i)
		{
			CItemWeapon* pWeapon = new CItemWeapon;
			pWeapon->Load(&file);

			m_vecWeapon.push_back(pWeapon);
		}

		file.Close();
	}

	file.Open("StoreArmor.sar", "rb");

	if (file.GetOpen())
	{
		size_t iArmorCount = 0;

		file.Read(&iArmorCount, 4);

		for (size_t i = 0; i < iArmorCount; ++i)
		{
			CItemArmor* pArmor = new CItemArmor;
			pArmor->Load(&file);

			m_vecArmor.push_back(pArmor);
		}

		file.Close();
	}

	cout << "���� �ҷ����� �Ϸ�" << endl;
	system("pause");
}
