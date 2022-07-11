
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


template<typename T>
void Safe_Delete_VecList(T)
{

}
template<typename T>
void Safe_Delete_Map(T& p)
{

}