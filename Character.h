#pragma once
#include "Obj.h"

class CCharacter	:
	public CObj
{
protected:
	CCharacter();
	virtual ~CCharacter();

protected:
	CHARACTER m_tInfo;

private:
	friend class CObjectManager;

public:
	virtual bool Init();
	virtual CObj* Clone();
	virtual void Render();
	void SetCharacterInfo(const char* name, int iMinDamage, int iMaxDamage, int	iMinArmor, int	iMaxArmor,
		int iHP, int iMP, int iExp, int iLevel);
	virtual int GetDamage();
	virtual int GetArmor();
	bool Die(int iDamage);
};

