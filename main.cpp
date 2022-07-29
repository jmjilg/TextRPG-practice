

#include "Core.h"
#include "EditorCore.h"

enum class CORE_MENU
{
	NONE,
	CORE,
	EDIT
};

int main()
{
	srand((unsigned int)time(0));

	int input;

	while (true)
	{
		system("cls");
		cout << "1. 게임" << endl;
		cout << "2. 툴" << endl;
		cout << "메뉴를 선택하시오. ";
		input = IntInput<int>();
		
		if (input <= 0 || input > 2)
			continue;

		else
			break;
	}

	switch (input)
	{
	case (int)CORE_MENU::CORE:
		if (!GET_SINGLE(CCore)->Init())
		{
			DESTROY_SINGLE(CCore);
			return 0;
		}
		GET_SINGLE(CCore)->Run();
		DESTROY_SINGLE(CCore);
		break;
	case (int)CORE_MENU::EDIT:
		if (!GET_SINGLE(CEditorCore)->Init())
		{
			DESTROY_SINGLE(CEditorCore);
			return 0;
		}
		GET_SINGLE(CEditorCore)->Run();
		DESTROY_SINGLE(CEditorCore);
		break;
	}

}