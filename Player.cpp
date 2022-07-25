
#include "Player.h"
#include "ObjectManager.h"
#include "Item.h"
#include "Inventory.h"
#include "Item.h"
#include "ItemWeapon.h"
#include "ItemArmor.h"
#include "Core.h"

CPlayer::CPlayer()
{
	memset(m_pEquip, 0, sizeof(CItem*) * 2);
}

CPlayer::~CPlayer()
{
}

CPlayer::CPlayer(const CPlayer& player) :
	CCharacter(player)
{
	m_iGold = player.m_iGold;
	m_eJob = player.m_eJob;
	m_strJobName = player.m_strJobName;
	memset(m_pEquip, 0, sizeof(CItem*) * (int)EQUIP::END);
}

bool CPlayer::Init()
{
	char pName[NAME_LENGTH];

	strcpy_s(pName, SetPlayerName());

	switch (SetPlayerJob())
	{
	case (int)JOB::WORRIAR:
		m_eJob = JOB::WORRIAR;
		SetCharacterInfo(pName, 5, 10, 10, 15, 200, 100, 0, 1);
		break;
	case (int)JOB::ARCHER:
		m_eJob = JOB::ARCHER;
		SetCharacterInfo(pName, 7, 12, 7, 12, 150, 150, 0, 1);
		break;
	case (int)JOB::WIZARD:
		m_eJob = JOB::WIZARD;
		SetCharacterInfo(pName, 10, 15, 5, 7, 100, 200, 0, 1);
		break;
	}

	m_iGold = 10000;

	return true;
}

void CPlayer::Render()
{

	cout << "�̸� : " << m_tInfo.name << "\t����ġ : " << m_tInfo.iExp << endl;

	if (!EquipEmpty(ITEM_TYPE::WEAPON)) 
	{
		CItemWeapon* pWeapon = (CItemWeapon*)m_pEquip[(int)EQUIP::WEAPON];
		cout << "���ݷ� : " << m_tInfo.iMinDamage << " + " << pWeapon->GetAttackMin()
			<< " ~ " << m_tInfo.iMaxDamage << " + " << pWeapon->GetAttackMax() << endl;
	}
	else
		cout << "���ݷ� : " << m_tInfo.iMinDamage << "~" << m_tInfo.iMaxDamage << endl;


	if (!EquipEmpty(ITEM_TYPE::ARMOR))
	{
		CItemArmor* pArmor = (CItemArmor*)m_pEquip[(int)EQUIP::ARMOR];
		cout << "���� : " << m_tInfo.iMinArmor << " + " << pArmor->GetArmorMin()
			<< "~" << m_tInfo.iMaxArmor << " + " << pArmor->GetArmorMax() << endl;
	}
	else
		cout << "\t���� : " << m_tInfo.iMinArmor << " ~ " << m_tInfo.iMaxArmor << endl;



	cout << "ü�� : " << m_tInfo.iHP << "/" << m_tInfo.iHPmax << "\t���� : " <<
		m_tInfo.iMP << "/" << m_tInfo.iMPmax << endl;
	cout << "���� : " << m_tInfo.iLevel;
	cout << "\t������ : " << m_iGold << endl;



	cout << "���� : ";
	if (!EquipEmpty(ITEM_TYPE::WEAPON))
		m_pEquip[(int)EQUIP::WEAPON]->Render();

	else
		cout << "����";

	cout << endl;

	cout << "�� : ";
	if (!EquipEmpty(ITEM_TYPE::ARMOR))
		m_pEquip[(int)EQUIP::ARMOR]->Render();

	else
		cout << "����";


	cout << endl << endl;
}

CObj* CPlayer::Clone()
{
	return new CPlayer(*this);
}

char* CPlayer::SetPlayerName()
{
	cout << "�̸��� �Է��ϼ��� : ";
	char name[NAME_LENGTH];
	cin.getline(name, NAME_LENGTH - 1, '\n');

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

		if (input <= (int)JOB::NONE || input > (int)JOB::WIZARD) {
			cin.ignore();
			continue;
		}

		return input;
	}

}

int CPlayer::GetDamage()
{
	if (!EquipEmpty(ITEM_TYPE::WEAPON))
	{
		CItemWeapon* pWeapon = (CItemWeapon*)m_pEquip[(int)EQUIP::WEAPON];
		return rand() %
			(m_tInfo.iMaxDamage + pWeapon->GetAttackMax() - 
				m_tInfo.iMinDamage - pWeapon->GetAttackMin() + 1) +
			m_tInfo.iMinDamage + pWeapon->GetAttackMin();
	}
	else
		return CCharacter::GetDamage();
}

int CPlayer::GetArmor()
{
	if (!EquipEmpty(ITEM_TYPE::ARMOR))
	{
		CItemArmor* pArmor = (CItemArmor*)m_pEquip[(int)EQUIP::ARMOR];
		return rand() %
			(m_tInfo.iMaxArmor + pArmor->GetArmorMax() -
				m_tInfo.iMinArmor - pArmor->GetArmorMin() + 1) +
			m_tInfo.iMinArmor + pArmor->GetArmorMin();
	}
	else
		return CCharacter::GetArmor();
}

CItem* CPlayer::Equip(CItem* pItem)
{
	CItem* temp = NULL;

	switch (pItem->GetItemType())
	{
	case ITEM_TYPE::WEAPON:
		if (!EquipEmpty(ITEM_TYPE::WEAPON))
			temp = m_pEquip[(int)EQUIP::WEAPON];

		m_pEquip[(int)EQUIP::WEAPON] = pItem;
		break;
	case ITEM_TYPE::ARMOR:
		if (!EquipEmpty(ITEM_TYPE::ARMOR))
			temp = m_pEquip[(int)EQUIP::ARMOR];

		m_pEquip[(int)EQUIP::ARMOR] = pItem;
		break;
	}

	return temp;
}

bool CPlayer::LevelupCheck()
{
	return m_tInfo.iExp >= g_iLvUpTable[m_tInfo.iLevel - 1];
}

void CPlayer::Levelup(JOB eJob)
{
	LEVELUPINFO tLevelupInfo = GET_SINGLE(CCore)->GetLevelupInfo(eJob);

	cout << "������!" << endl;
	m_tInfo.iLevel++;
	m_tInfo.iMinDamage += tLevelupInfo.iMinDamage;
	m_tInfo.iMaxDamage += tLevelupInfo.iMaxDamage;
	m_tInfo.iMinArmor += tLevelupInfo.iMinArmor;
	m_tInfo.iMaxArmor += tLevelupInfo.iMaxArmor;
	m_tInfo.iHPmax += tLevelupInfo.iHP;
	m_tInfo.iHP += tLevelupInfo.iHP;
	m_tInfo.iMPmax += tLevelupInfo.iMP;
	m_tInfo.iMP += tLevelupInfo.iMP;
}



