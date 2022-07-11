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
	WIZARD
};

enum class BATTLE : int
{
	NONE,
	ATTACK,
	RUN_AWAY
};

enum class STAGE_LEVEL : int
{
	NONE,
	EASY,
	NORMAL,
	HARD
};

enum class OBJECT_TYPE : int
{
	NONE,
	PLAYER,
	MONSTER
};

enum class STAGE_TYPE : int
{
	NONE,
	EASY,
	NORMAL,
	HARD,
	BACK
};