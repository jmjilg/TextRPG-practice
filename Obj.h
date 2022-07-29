#pragma once

#include"value.h"

class CObj
{
protected:
	CObj();
	CObj(const CObj& obj);
	virtual ~CObj() = 0;

private:
	friend class CObjectManager;
protected:    
	JOB     m_eJob;
	string m_strName;
	OBJECT_TYPE m_eType;

public:
	void SetName(const char* pName)
	{
		m_strName = pName;
	}

	string GetName()	const
	{
		return m_strName;
	}
	OBJECT_TYPE GetObjectType()	const
	{
		return m_eType;
	}
	virtual bool Init();
	virtual CObj* Clone() = 0;
	virtual void Render() = 0;
	virtual void Save(class CFileStream* pFile);
	virtual void Load(class CFileStream* pFile);
};

