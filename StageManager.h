#pragma once
class CStageManager
{
public:
	CStageManager();
	~CStageManager();

public:
	static CStageManager* m_pInst;

public:
	static CStageManager* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CStageManager;

		return m_pInst;
	}

public:
	void Init();
	void Run();
};

