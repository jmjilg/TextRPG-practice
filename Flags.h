#pragma once


enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_INFO,
	MM_END
};

enum class JOB : int
{
	NONE,
	WORRIAR,
	ARCHER,
	WIZARD,
	MAX
};

enum class STAGE_LEVEL : int
{
	NONE,
	EASY,
	NORMAL,
	HARD,
	BACK
};

enum class OBJECT_TYPE : int
{
	NONE,
	PLAYER,
	MONSTER,
	WEAPON,
	ARMOR
};

enum class STAGE_TYPE : int
{
	NONE,
	EASY,
	NORMAL,
	HARD,
	BACK
};

enum class STORE_MENU
{
	NONE,
	WEAPON,
	ARMOR,
	BACK
};

enum class ITEM_TYPE
{
	NONE,
	WEAPON,
	ARMOR
};

