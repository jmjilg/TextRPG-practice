#pragma once

class CMonster;
class CPlayer;
class CStageEasy
{
public:
	CStageEasy();
	~CStageEasy();

private:
	CMonster* m_pMonster;

public:
	void Init();
	void Run(class CPlayer* pPlayer);
	void Battle(CPlayer* pPlayer, CMonster* pMonster);
};

