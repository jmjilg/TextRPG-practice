#pragma once

#include "value.h"

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

private:
	PCHARACTER m_pInfo;

public:
	void Init();
	void Create(const char* name, int iMinDamage, int iMaxDamage, int	iMinArmor, int	iMaxArmor,
		int iHP, int iMP, int iExp, int iLevel);
};

