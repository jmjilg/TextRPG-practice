
#include "Stage.h"
#include "value.h"
#include "Monster.h"
#include "Player.h"

CStage::CStage()
{
}

CStage::~CStage()
{
}

void CStage::OutputStageName(const char* pName)
{
	cout << "========================	" << pName << " ========================" << endl;
}

int CStage::OutputMenu()
{
	while (true)
	{
		cout << "1. 공격" << endl;
		cout << "2. 도망간다" << endl;
		cout << "행동을 선택하세요 : ";
		int input;
		input = IntInput<int>();

		if (input <= (int)BATTLE::NONE || input > (int)BATTLE::RUN_AWAY)
			continue;

		return input;
	}
}

CStage::BATTLE_FLAG CStage::BattleAttack(CPlayer* pPlayer, CMonster* pMonster)
{
	int iDamage = pPlayer->GetDamage();
	int iArmor = pMonster->GetArmor();

	// 몬스터의 방어력이 플레이어의 공격력 보다 높을 시 데미지는 1만 들어감
	iDamage = iDamage <= iArmor ? 1 : iDamage - iArmor;	

	// 플레이어가 몬스터 쓰려뜨렸을 시
	if (pMonster->Die(iDamage))
		return BATTLE_FLAG::PLAYER_WIN;

	// 몬스터가 플레이어 공격
	iDamage = pMonster->GetDamage();
	iArmor = pPlayer->GetArmor();

	iDamage = iDamage <= iArmor ? 1 : iDamage - iArmor;


	// 플레이어가 몬스터에게 패배했을 시
	if (pPlayer->Die(iDamage))
		return BATTLE_FLAG::PLAYER_DIE;
}

