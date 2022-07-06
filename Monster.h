#pragma once

#include "value.h"

class CMonster
{
public:
	CMonster();
	~CMonster();

private:
	PCHARACTER  m_pInfo;
	int			iGold;

	friend class CStageEasy;
	friend class CStageNormal;
	friend class CStageHard;

public:
	void Create(const char* name, int	iMinDamage, int iMaxDamage, int	iMinArmor, int	iMaxArmor,
		int iHP, int iMP, int iExp, int iLevel, int iGold);
	void Info();
};

