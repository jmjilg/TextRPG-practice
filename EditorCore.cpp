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
		cout << "1. ���� ������" << endl;
		cout << "2. ������ ������" << endl;
		cout << "3. ����" << endl;
		cout << "�޴��� �Է��ϼ��� :";
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

