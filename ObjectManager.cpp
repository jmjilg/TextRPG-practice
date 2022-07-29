#include "ObjectManager.h"
#include "Obj.h"
#include "Player.h"
#include "Monster.h"
#include "ItemWeapon.h"
#include "ItemArmor.h"
#include "FileStream.h"

DEFINITION_SINGLE(CObjectManager)

CObjectManager::CObjectManager()
{
}

CObjectManager::~CObjectManager()
{
}

bool CObjectManager::Init()
{
	CPlayer* pPlayer = NULL;

	pPlayer = (CPlayer*)GET_SINGLE(CObjectManager)->CreateObject("Player", OBJECT_TYPE::PLAYER);
	pPlayer->Init();

	CFileStream file("MonsterList.mtl", "rb");

	if (file.GetOpen())
	{
		int iMonsterCount = 0;

		file.Read(&iMonsterCount, 4);

		for (int i = 0; i < iMonsterCount; ++i)
		{
			CMonster* pMonster = new CMonster;

			pMonster->Load(&file); //오류

			m_mapObj.insert(make_pair(pMonster->GetName(), pMonster));
		}
	}

	else
	{
		CMonster* pMonster = NULL;

		pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CreateObject("Goblin", OBJECT_TYPE::MONSTER);
		pMonster->SetCharacterInfo(5, 10, 5, 10, 100, 100, 100, 1);
		pMonster->SetName("고블린");
		pMonster->SetGold(1000, 1500);

		pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CreateObject("Troll", OBJECT_TYPE::MONSTER);
		pMonster->SetCharacterInfo(10, 20, 20, 30, 400, 200, 300, 5);
		pMonster->SetName("트롤");
		pMonster->SetGold(3000, 5000);

		pMonster = (CMonster*)GET_SINGLE(CObjectManager)->CreateObject("Dragon", OBJECT_TYPE::MONSTER);
		pMonster->SetCharacterInfo(50, 70, 40, 60, 700, 500, 1000, 1);
		pMonster->SetName("드래곤");
		pMonster->SetGold(10000, 15000);
	}

	return true;
}

CObj* CObjectManager::CreateObject(const string& strKey, OBJECT_TYPE eType)
{
	CObj* pObj = NULL;

	switch (eType)
	{
	case OBJECT_TYPE::PLAYER:
		pObj = new CPlayer;
		break;
	case OBJECT_TYPE::MONSTER:
		pObj = new CMonster;
		break;
	case OBJECT_TYPE::WEAPON:
		pObj = new CItemWeapon;
		break;
	case OBJECT_TYPE::ARMOR:
		pObj = new CItemArmor;
		break;
	}

	m_mapObj.insert(make_pair(strKey, pObj));

	return pObj;
}

CObj* CObjectManager::FindObject(const string& strKey)
{

	unordered_map<string, CObj*>::iterator iter = m_mapObj.find(strKey);

	if (iter == m_mapObj.end())
		return NULL;


	return iter->second;
}

CObj* CObjectManager::CloneObject(const string& strKey)
{
	CObj* pOrig = FindObject(strKey);

	if (!pOrig)
		return NULL;

	return pOrig->Clone();
}

CObj* CObjectManager::CloneObject(STAGE_LEVEL eType)
{
	CObj* pObj = NULL;

	vector<CMonster*> vecMonster;

	unordered_map<string, CObj*>::iterator iter;
	for (iter = m_mapObj.begin(); iter != m_mapObj.end(); ++iter)
	{
		if (iter->second->GetObjectType() == OBJECT_TYPE::MONSTER)
		{
			CMonster* pMonster = (CMonster*)iter->second;

			if(pMonster->GetStageLevel() == eType)
				vecMonster.push_back((CMonster*)iter->second);
		}
	}

	if (vecMonster.empty())
		return NULL;

	int idx = rand() % vecMonster.size();

	return vecMonster[idx]->Clone();
}






//CObj* CObjectManager::CloneObject(OBJECT_TYPE eType)
//{
//	unordered_map<string, CObj*>::iterator iter;
//
//	vector<CObj*> vec;
//
//	for (iter = m_mapObj.begin(); iter != m_mapObj.end(); ++iter)
//	{
//		if (iter->second->GetObjectType() == eType)
//		{
//			CObj* pObj = iter->second->Clone();
//			vec.push_back(iter->second);
//			delete pObj;
//		}
//	}
//
//	return nullptr;
//}
