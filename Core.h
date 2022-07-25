#pragma once

#include "value.h"

class CCore
{
	DECLARE_SINGLE(CCore)

private:
	LEVELUPINFO m_tLevelupInfo[(int)JOB::MAX - 1] = {};

public:
	LEVELUPINFO GetLevelupInfo(JOB eJob);

public:
	bool Init();
	void Run();
	int OutputMenu();
	LEVELUPINFO CreateLevelupInfo(int iMinDamage, int iMaxDamage, int iMinArmor, int iMaxArmor,
		int iHP, int iMP);
	void SetLevelupInfo();

};

