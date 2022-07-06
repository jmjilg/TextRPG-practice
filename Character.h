#pragma once
#include "value.h"

class CCharacter
{
public:
	CCharacter();
	~CCharacter();

private:
	static CCharacter* m_pInst;
public:
	static CCharacter* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CCharacter;

		return m_pInst;
	}
};

