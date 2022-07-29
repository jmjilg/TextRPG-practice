
#include "Obj.h"
#include "FileStream.h"

CObj::CObj()
{
}

CObj::CObj(const CObj& obj)
{
	m_strName = obj.m_strName;
	m_eType = obj.m_eType;
}

CObj::~CObj()
{
}

bool CObj::Init()
{
	return true;
}

void CObj::Save(CFileStream* pFile)
{
	pFile->Write(&m_eJob, sizeof(JOB));

	int iLength = m_strName.length();

	pFile->Write(&iLength, 4);

	pFile->Write((void*)m_strName.c_str(), iLength);
	pFile->Write(&m_eType, sizeof(m_eType));

}

void CObj::Load(CFileStream* pFile)
{
	pFile->Read(&m_eJob, sizeof(JOB));


	int iLength;
	pFile->Read(&iLength, 4);

	char* pName = new char[iLength +1];
	memset(pName, 0, iLength);

	pFile->Read(pName, iLength);
	pName[iLength] = 0;

	m_strName = pName;

	pFile->Read(&m_eType, sizeof(m_eType));

	SAFE_DELETE(pName);
}
