
#include "Player.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	m_iGold = 10000;
	return true;
}

void CPlayer::Render()
{
	CCharacter::Render();
	cout << "������ : " << m_iGold << endl << endl;
}

CObj* CPlayer::Clone()
{
	return new CPlayer(*this);
}
