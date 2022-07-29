#pragma once
#include "value.h"

class CEditorCore
{
private:
	enum class EDITOR_MENU
	{
		NONE,
		MONSTER,
		ITEM,
		EXIT
	};

public:
	bool Init();
	void Run();

	DECLARE_SINGLE(CEditorCore)
};

