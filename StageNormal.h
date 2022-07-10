#pragma once

#include "Monster.h"
#include "Player.h"

class CStageNormal
{
public:
	CStageNormal();
	~CStageNormal();

private:
	class CMonster* m_pMonster;


public:
	void Init();
	void Run(class CPlayer* pPlayer);
	void Battle(CPlayer* pPlayer, CMonster* pMonster);
};

