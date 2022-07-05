#pragma once

class CCore
{
private:
	CCore();
	~CCore();

private:
	static CCore* m_pInst;
	
public:
	static CCore* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CCore;

		return m_pInst;
	}

public:
	void Init();
	void Run();
};

