#pragma once

#include"value.h"

class CObj
{
protected:
	CObj();
	virtual ~CObj() = 0;

private:
	friend class CObjectManager;
protected:    
	JOB     m_eJob;
	string  m_strJobName;
	string m_strName;
	OBJECT_TYPE m_eType;

public:
	virtual bool Init();
	virtual CObj* Clone() = 0;
	virtual void Render() = 0;
	virtual OBJECT_TYPE GetObjectType() = 0;

	void SetName(const char* pName)
	{
		m_strName = pName;
	}

	string GetName()	const
	{
		return m_strName;
	}
};

