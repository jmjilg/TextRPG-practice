#pragma once
#include "Character.h"

class CItem;
class CPlayer :
	public CCharacter
{
public:
	CPlayer();
	virtual ~CPlayer();
	CPlayer(const CPlayer& player);

private:
	enum class EQUIP
	{
		WEAPON,
		ARMOR,
		END
	};

private:
	friend class CObj;
	friend class CInventory;

private:
	JOB     m_eJob;
	string  m_strJobName;
	int m_iGold;
	CItem* m_pEquip[(int)EQUIP::END];

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

	bool EquipEmpty(ITEM_TYPE eType)
	{
		if (m_pEquip[(int)eType-1] == NULL)
			return true;

		return false;
	}
	
	CItem* Equip(CItem* pItem);

};

