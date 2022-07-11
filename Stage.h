#pragma once

class CStage
{
public:
	CStage();
	~CStage();

public:
	virtual bool Init() = 0;
	virtual void Run() = 0;

private:
	enum class BATTLE_FLAG : int
	{
		PLAYER_WIN,
		PLAYER_DIE,
	};

protected:
	void OutputStageName(char* pName);
	int OutputMenu();
	BATTLE_FLAG BattleAttack(class CPlayer* pPlayer, class CMonster* pMonster);
};

