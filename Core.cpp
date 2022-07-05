
#include "Core.h"
#include "value.h"

CCore* CCore::m_pInst = NULL;

CCore::CCore()
{
}

CCore::~CCore()
{
	SAFE_DELETE(m_pInst)
}

void CCore::Init()
{
}

void CCore::Run()
{
	while (true)
	{
		cout << "메뉴를 입력하세요: ";
		int input = IntInput<int>();

		if (input <= MM_NONE || input > MM_END)
			continue;

		switch (input)
		{
		case MM_MAP:
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		case MM_INFO:
			break;
		case MM_END:
			return;
		}
	}
}
