#pragma once

#include "Monster.h"
#include "Player.h"

class CStageHard
{
public:
	CStageHard();
	~CStageHard();

private:
	class CMonster* m_pMonster;


public:
	void Init();
	void Run(class CPlayer* pPlayer);
	void Battle(CPlayer* pPlayer, CMonster* pMonster);
};

