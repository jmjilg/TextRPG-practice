#pragma once

#include "Item.h"

class CItemWeapon	:
	public CItem
{
private:
	CItemWeapon();

public:
	~CItemWeapon();

private:
	friend class CObjectManager;
	friend class CStore;
	friend class CStoreWeapon;
	friend class CStoreManager;

private:
	int m_iAttackMin;
	int m_iAttackMax;
	float m_fCritical;

public:
	virtual void Render();
	virtual CItem* Clone();
	OBJECT_TYPE GetObjectType()
	{
		return OBJECT_TYPE::MONSTER;
	}
	void SetWeaponInfo(int iAttackMin, int iAttackMax, int iCritical)
	{
		m_iAttackMin = iAttackMin;
		m_iAttackMax = iAttackMax;
		m_fCritical = iCritical;
	}
};

