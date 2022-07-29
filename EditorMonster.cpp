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
	cout << "이름을 입력하세요 : ";
	cin >> pName;

	cout << "최소 데미지 :";
	cin >> iMinDamage;

	cout << "최대 데미지 :";
	cin >> iMaxDamage;

	cout << "최소 방어력 :";
	cin >> iMinArmor;

	cout << "최대 방어력 :";
	cin >> iMaxArmor;

	cout << "체력 :";
	cin >> iHP;

	cout << "마나 :";
	cin >> iMP;

	cout << "경험치 :";
	cin >> iExp;

	cout << "레벨 :";
	cin >> iLevel;

	pMonster->SetName(pName);
	pMonster->SetCharacterInfo(iMinDamage, iMaxDamage, iMinArmor, iMaxArmor,
		iHP, iMP, iExp, iLevel);

	int iGoldMin, iGoldMax;
	cout << "최소 소지금 :";
	cin >> iGoldMin;

	cout << "최대 소지금 :";
	cin >> iGoldMax;

	pMonster->SetGold(iGoldMin, iGoldMax);

	while (true)
	{
		cout << "1. 쉬움" << endl;
		cout << "2. 보통" << endl;
		cout << "3. 어려움" << endl;
		cout << "난이도를 선택하시오 ";
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
		cout << "1. 몬스터 추가" << endl;
		cout << "2. 몬스터 수정" << endl;
		cout << "3. 몬스터 삭제" << endl;
		cout << "4. 몬스터 목록" << endl;
		cout << "5. 저장" << endl;
		cout << "6. 불러오기" << endl;
		cout << "7. 뒤로가기" << endl;
		cout << "메뉴를 선택하세요 : ";
		
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
	cout << "================== 파일 저장 ==================" << endl;

	CFileStream file("MonsterList.mtl", "wb");

	size_t iMonsterCount = m_vecMonster.size();

	file.Write(&iMonsterCount, 4);

	for (size_t i = 0; i < iMonsterCount; ++i)
	{
		m_vecMonster[i]->Save(&file);
	}

	cout << "파일 저장 완료" << endl;
	system("pause");

}

void CEditorMonster::Load()
{
	system("cls");
	cout << "================== 파일 불러오기 ==================" << endl;

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

	cout << "파일 불러오기 완료" << endl;
	system("pause");
}

