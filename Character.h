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
	void SetCharacterInfo(int iMinDamage, int iMaxDamage, int	iMinArmor, int	iMaxArmor,
		int iHP, int iMP, int iExp, int iLevel);
	virtual int GetDamage();
	virtual int GetArmor();
	bool Die(int iDamage);
	virtual void Save(class CFileStream* pFile);
	virtual void Load(class CFileStream* pFile);
};

