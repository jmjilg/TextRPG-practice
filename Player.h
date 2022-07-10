#pragma once
#include "Character.h"

class CPlayer :
	public CCharacter
{
public:
	CPlayer();
	virtual ~CPlayer();

private:
	friend class CObj;

private:
	int m_iGold;

public:
	virtual bool Init();
	virtual void Render();
	virtual CObj* Clone();
	OBJECT_TYPE GetObjectType()
	{
		return OBJECT_TYPE::PLAYER;
	}
};

