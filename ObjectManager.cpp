#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"

DEFINITION_SINGLE(CObjectManager)

CObjectManager::CObjectManager()
{
}

CObjectManager::~CObjectManager()
{
}

bool CObjectManager::Init()
{
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
