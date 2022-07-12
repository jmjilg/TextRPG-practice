#pragma once

#include "Character.h"

class CMonster	:
	public CCharacter
{
public:
	CMonster();
	virtual ~CMonster();

private:
	friend class CObj;

private:
	int m_iGoldMin;
	int m_iGoldMax;

public:
	virtual bool Init();
	virtual void Render();
	virtual CObj* Clone();
	OBJECT_TYPE GetObjectType()
	{
		return OBJECT_TYPE::MONSTER;
	}
	int GetGold();
	int GetExp();
	void SetGold(int iGoldMin, int iGoldMax);
};

