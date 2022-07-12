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
	char* SetPlayerName();
	int SetPlayerJob();

	OBJECT_TYPE GetObjectType()
	{
		return OBJECT_TYPE::PLAYER;
	}
	void SetGold(int iGold)
	{
		m_iGold += iGold;
	}
	int GetGold()	const
	{
		return m_iGold;
	}
	void SetExp(int iExp)
	{
		m_tInfo.iExp += iExp;
	}
	int GetExp()	const
	{
		return m_tInfo.iExp;
	}
	void Heal()
	{
		m_tInfo.iHP = m_tInfo.iHPmax;
	}
};

