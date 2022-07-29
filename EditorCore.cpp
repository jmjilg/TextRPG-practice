#include "EditorCore.h"
#include "EditorMonster.h"
#include "EditorItem.h"

DEFINITION_SINGLE(CEditorCore)

CEditorCore::CEditorCore()
{
}

CEditorCore::~CEditorCore()
{
	DESTROY_SINGLE(CEditorMonster);
	DESTROY_SINGLE(CEditorItem);
}

bool CEditorCore::Init()
{
	if (!GET_SINGLE(CEditorMonster)->Init())
		return false;
	
	if (!GET_SINGLE(CEditorItem)->Init())
		return false;

	return true;
}

void CEditorCore::Run()
{
	int input;

	while (true)
	{
		system("cls");
		cout << "1. 몬스터 에디터" << endl;
		cout << "2. 아이템 에디터" << endl;
		cout << "3. 종료" << endl;
		cout << "메뉴를 입력하세요 :";
		input = IntInput<int>();

		if (input <= (int)EDITOR_MENU::NONE || input > (int)EDITOR_MENU::EXIT)
			continue;

		switch (input)
		{
		case (int)EDITOR_MENU::MONSTER:
			GET_SINGLE(CEditorMonster)->Run();
			break;
		case (int)EDITOR_MENU::ITEM:
			GET_SINGLE(CEditorItem)->Run();
			break;
		case (int)EDITOR_MENU::EXIT:
			return;
		}
	}
}

