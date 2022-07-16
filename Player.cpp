
#include "Player.h"
#include "ObjectManager.h"

CPlayer::CPlayer()
{

}

CPlayer::~CPlayer()
{
}

CPlayer::CPlayer(const CPlayer& player)	:
	CCharacter(player)
{
	m_iGold = player.m_iGold;
	m_eJob = player.m_eJob;
	m_strJobName = player.m_strJobName;
	memset(m_pEquip, 0, sizeof(CItem*)*(int)EQUIP::END);
}

bool CPlayer::Init()
{
	char pName[NAME_LENGTH];

	strcpy_s(pName, SetPlayerName());

	switch (SetPlayerJob())
	{
	case (int)JOB::WORRIAR:
		SetCharacterInfo(pName, 5, 10, 10, 15, 200, 100, 0, 1);
		break;
	case (int)JOB::ARCHER:
		SetCharacterInfo(pName, 7, 12, 7, 12, 150, 150, 0, 1);
		break;
	case (int)JOB::WIZARD:
		SetCharacterInfo(pName, 10, 15, 5, 7, 100, 200, 0, 1);
		break;
	}

	m_iGold = 10000;

	return true;
}

void CPlayer::Render()
{
	CCharacter::Render();
	cout << "\t������ : " << m_iGold << endl << endl;
}

CObj* CPlayer::Clone()
{
	return new CPlayer(*this);
}

char* CPlayer::SetPlayerName()
{
	cout << "�̸��� �Է��ϼ��� : ";
	char name[NAME_LENGTH];
	cin >> name;
	cin.ignore();

	return name;
}

int CPlayer::SetPlayerJob()
{
	while (true)
	{
		system("cls");
		cout << "1. ����" << endl;
		cout << "2. �ü�" << endl;
		cout << "3. ������" << endl;
		cout << "������ �����ϼ���: ";
		int input = IntInput<int>();

		if (input <= (int)JOB::NONE || input >(int)JOB::WIZARD) {
			cin.ignore();
			continue;
		}

		return input;
	}

}

