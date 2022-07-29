#pragma once

#include "Character.h"

class CMonster	:
	public CCharacter
{
private:
	CMonster();
	CMonster(const CMonster& monster);

public:
	virtual ~CMonster();

private:
	friend class CObjectManager;
	friend class CEditorMonster;

private:
	int m_iGoldMin;
	int m_iGoldMax;
	STAGE_LEVEL m_eStageLevel;

public:
	virtual bool Init();
	virtual void Render();
	virtual CObj* Clone();
	OBJECT_TYPE GetObjectType()	const
	{
		return OBJECT_TYPE::MONSTER;
	}
	STAGE_LEVEL GetStageLevel()	const
	{
		return m_eStageLevel;
	}
	void SetStageLevel(STAGE_LEVEL eStageLevel)
	{
		m_eStageLevel = eStageLevel;
	}
	int GetGold();
	int GetExp();
	void SetGold(int iGoldMin, int iGoldMax);

	virtual void Save(class CFileStream* pFile);
	virtual void Load(class CFileStream* pFile);
};

