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
	WORRIAR,
	ARCHER,
	WIZARD
};

enum class BATTLE : int
{
	ATTACK,
	RUN_AWAY
};

enum class STAGE_LEVEL : int
{
	EASY,
	NORMAL,
	HARD
};

enum class OBJECT_TYPE : int
{
	PLAYER,
	MONSTER
};

