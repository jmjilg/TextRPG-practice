

#include "Core.h"
#include "EditorCore.h"
int main()
{
	srand((unsigned int)time(0));

	int input;

	while (true)
	{
		system("cls");
		cout << "1. ����" << endl;
		cout << "2. ��" << endl;
		cout << "�޴��� �����Ͻÿ�. ";
		input = IntInput<int>();
		
		if (input <= 0 || input > 2)
			continue;

		else
			break;
	}

	switch (input)
	{
	case 1:
		GET_SINGLE(CCore)->Init();
		GET_SINGLE(CCore)->Run();
		break;
	case 2:
		GET_SINGLE(CEditorCore)->Init();
		GET_SINGLE(CEditorCore)->Run();
		break;
	}

}