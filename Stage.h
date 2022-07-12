#pragma once

class CStage
{
public:
	CStage();
	~CStage();

public:
	virtual bool Init() = 0;
	virtual void Run() = 0;

protected:
	enum class BATTLE_FLAG : int
	{
		NONE,
		PLAYER_WIN,
		PLAYER_DIE,
	};

	enum class BATTLE : int
	{
		NONE,
		ATTACK,
		RUN_AWAY
	};

protected:
	void OutputStageName(const char* pName);
	int OutputMenu();
	BATTLE_FLAG BattleAttack(class CPlayer* pPlayer, class CMonster* pMonster);
};

