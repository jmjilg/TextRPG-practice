#pragma once

class CStage
{
public:
	CStage();
	~CStage();

private:
	static CStage* m_pInst;

public:
	static CStage* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CStage;

		return m_pInst;
	}

private:
	void Init();
	void Run();
};

