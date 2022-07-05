
#pragma once
#include <iostream>
#include "Macro.h"

using namespace std;

#define NAME_LENGTH		256

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
	int iMinDamage;
	int iMaxDamage;
	int iMinArmor;
	int iMaxArmor;
	int iHP;
	int iMP;
	int iExp;
	int iLevel;
	char name[NAME_LENGTH];
}CHARACTER, PCHATACTER;

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_INFO,
	MM_END
};