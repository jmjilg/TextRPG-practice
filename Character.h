#pragma once
#include "Obj.h"

class CCharacter	:
	public CObj
{
public:
	CCharacter();
	virtual ~CCharacter();

protected:
	CHARACTER m_tInfo;

public:
	virtual bool Init();
	virtual CObj* Clone();
	virtual void Render();
	void SetCharacterInfo(const char* name, int iMinDamage, int iMaxDamage, int	iMinArmor, int	iMaxArmor,
		int iHP, int iMP, int iExp, int iLevel);
	int GetDamage();
	int GetArmor();
	bool Die(int iDamage);
};

