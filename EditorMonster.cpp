#include "EditorMonster.h"
#include "Obj.h"
#include "Character.h"
#include "Monster.h"
#include "FileStream.h"

DEFINITION_SINGLE(CEditorMonster)

CEditorMonster::CEditorMonster()
{
}

CEditorMonster::~CEditorMonster()
{
	Safe_Delete_VecList(m_vecMonster);
}

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

bool CEditorMonster::Init()
{
	return true;
}

void CEditorMonster::Run()
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


void CEditorMonster::Insert()
{
	CMonster* pMonster = new CMonster;

	if (!pMonster->Init())
	{
		SAFE_DELETE(pMonster);
		return;
	}

	char pName[NAME_LENGTH] = {};
	int iMinDamage, iMaxDamage, iMinArmor, iMaxArmor, iHP, iMP, iExp, iLevel;
	
	system("cls");
	cout << "�̸��� �Է��ϼ��� : ";
	cin >> pName;

	cout << "�ּ� ������ :";
	cin >> iMinDamage;

	cout << "�ִ� ������ :";
	cin >> iMaxDamage;

	cout << "�ּ� ���� :";
	cin >> iMinArmor;

	cout << "�ִ� ���� :";
	cin >> iMaxArmor;

	cout << "ü�� :";
	cin >> iHP;

	cout << "���� :";
	cin >> iMP;

	cout << "����ġ :";
	cin >> iExp;

	cout << "���� :";
	cin >> iLevel;

	pMonster->SetName(pName);
	pMonster->SetCharacterInfo(iMinDamage, iMaxDamage, iMinArmor, iMaxArmor,
		iHP, iMP, iExp, iLevel);

	int iGoldMin, iGoldMax;
	cout << "�ּ� ������ :";
	cin >> iGoldMin;

	cout << "�ִ� ������ :";
	cin >> iGoldMax;

	pMonster->SetGold(iGoldMin, iGoldMax);

	while (true)
	{
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. �����" << endl;
		cout << "���̵��� �����Ͻÿ� ";
		STAGE_LEVEL iStage = (STAGE_LEVEL)IntInput<int>();

		if (iStage <= STAGE_LEVEL::NONE || iStage > STAGE_LEVEL::HARD)
			continue;

		pMonster->SetStageLevel(iStage);
		break;
	}

	m_vecMonster.push_back(pMonster);

}

int CEditorMonster::OutputMenu()
{
	int input;

	while (true)
	{
		system("cls");
		cout << "1. ���� �߰�" << endl;
		cout << "2. ���� ����" << endl;
		cout << "3. ���� ����" << endl;
		cout << "4. ���� ���" << endl;
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

void CEditorMonster::OutputList()
{
	for (size_t i = 0; i < m_vecMonster.size(); ++i)
	{
		cout << i + 1 << "." << endl;
		m_vecMonster[i]->Render();
	}
	system("pause");
}

void CEditorMonster::Save()
{
	system("cls");
	cout << "================== ���� ���� ==================" << endl;

	CFileStream file("MonsterList.mtl", "wb");

	size_t iMonsterCount = m_vecMonster.size();

	file.Write(&iMonsterCount, 4);

	for (size_t i = 0; i < iMonsterCount; ++i)
	{
		m_vecMonster[i]->Save(&file);
	}

	cout << "���� ���� �Ϸ�" << endl;
	system("pause");

}

void CEditorMonster::Load()
{
	system("cls");
	cout << "================== ���� �ҷ����� ==================" << endl;

	CFileStream file("MonsterList.mtl", "rb");

	size_t iMonsterCount = 0;

	file.Read(&iMonsterCount, 4);

	for (size_t i = 0; i < iMonsterCount; ++i)
	{
		CMonster* pMonster = new CMonster;
		if (!pMonster->Init())
		{
			SAFE_DELETE(pMonster);
			return;
		}
		pMonster->Load(&file);

		m_vecMonster.push_back(pMonster);
	}

	cout << "���� �ҷ����� �Ϸ�" << endl;
	system("pause");
}

