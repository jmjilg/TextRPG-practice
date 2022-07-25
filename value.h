
#pragma once
#include <iostream>
#include <time.h>
#include <unordered_map>
#include <string>
#include <vector>
#include <iterator>


using namespace std;

#include "defines.h"
#include "Flags.h"

#define NAME_LENGTH		32
#define STR_DESC_LENGTH		256
#define WEAPON_COUNT	3
#define ARMOR_COUNT		3
#define INVENTORY_SLOTMAX	10

template<typename T>
T IntInput()
{
	T	input;
	
	while (true) {
		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		return input;
	}
}

typedef struct _tagCharacter
{
	int					iMinDamage;
	int					iMaxDamage;
	int					iMinArmor;
	int					iMaxArmor;
	int					iHP;
	int					iHPmax;
	int					iMP;
	int					iMPmax;
	int					iExp;
	int					iLevel;
	char				name[NAME_LENGTH];
}CHARACTER, *PCHARACTER;

typedef struct _tagItem
{
	ITEM_TYPE	eType;
	string strTypeName;
	int iPrice;
	int iSell;
	char strDesc[STR_DESC_LENGTH];
}ITEMINFO, *PITEMINFO;

typedef struct _tagLevelupInfo
{
	int					iMinDamage;
	int					iMaxDamage;
	int					iMinArmor;
	int					iMaxArmor;
	int					iHP;
	int					iMP;
}LEVELUPINFO, *PLEVELUPINFO;

#define MAX_LEVEL	10

static int g_iLvUpTable[MAX_LEVEL] = { 4000, 10000, 20000, 35000, 52000, 72000, 90000, 130000,170000, 250000 };

template <typename T>
void Safe_Delete_VecList(T& p)
{
	typename T::iterator iter;
	typename T::iterator iterEnd = p.end();

	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE(*iter);
	}
	
	p.clear();
}
template <typename T>
void Safe_Delete_Map(T& p)
{
	typename T::iterator iter;
	typename T::iterator iterEnd = p.end();
	
	for (iter = p.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE(iter->second);
	}

	p.clear();

}