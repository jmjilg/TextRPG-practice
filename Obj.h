#pragma once

#include"value.h"

class CObj
{
public:
	CObj();
	virtual ~CObj();

private:
	OBJECT_TYPE OT;

public:
	virtual bool Init();
	virtual CObj* Clone() = 0;
	virtual void Render() = 0;
	virtual OBJECT_TYPE GetObjectType() = 0;
};

