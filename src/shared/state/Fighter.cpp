#include "Fighter.h"
#include <iostream>

using namespace std;

namespace state{
	// Fighter::Fighter(const Fighter & old)
	// {
	// 	cout << "test copie constructeur" << old.name << endl;

	// 	this->name = old.name;
	// 	cout << "test copie constructeur" << this->name << endl;
	// }

	Fighter:: Fighter()
	{
		
	}

	Fighter:: Fighter(int playerID, FighterName name)
	{
		this-> playerID = playerID;
		this-> name = name;
	}


	Fighter::Fighter(FighterName name, int playerID, FighterStatus status, int healthPointsMax, int healthPoints,int movePoints,int combo,Attack attak, int mana)
	{
		this->name = name;
		this->playerID = playerID;
		this->status = status;
		this->healthPointsMax = healthPointsMax;
		this->healthPoints = healthPoints;
		this->combo=combo;
		this->attak=attak;
		this->mana = mana;
	}
	
	int Fighter::damageCompute(int damage)
	{	
		healthPoints = healthPoints - damage;
		if(healthPoints <0) healthPoints=0;
		return healthPoints;
	}

	

	void Fighter::fight(Fighter& target, Attack attack)
	{
		int damage =0;
		if(mana >=30)
		{
			if(attack==COUPDEPOING && target.status!=DEFENSE)
			{
				attak = COUPDEPOING; //attak is the value uses 
				damage = 20;		//for defining the variable
				target.damageCompute(damage); // attack in Fighter
				mana -= 30;
			}
			if(attack==COUPDEPIED && target.status!=DEFENSE)
			{
				attak = COUPDEPIED;
				damage = 20;
				target.damageCompute(damage);
				mana -= 30;
			}
			if(attack==UPPERCUT && target.status!=DEFENSE)
			{
				attak = UPPERCUT;
				damage = 30;
				target.damageCompute(damage);
				mana -= 30;
			}
					
			if(attack==FLASH_KICK && target.status!=DEFENSE)
			{
				attak = FLASH_KICK;
				damage = 30;
				target.damageCompute(damage);
				mana -= 30;
			}
			//target defending
			if(target.status == DEFENSE)
			{
				if(attack == COUPDEPOING )
				{
					damage = 10;
					target.damageCompute(damage);
					mana -=30;
				}
				if(attack == COUPDEPIED )
				{
					damage = 10;
					target.damageCompute(damage);
					mana -=30;
				}
				if(attack == FLASH_KICK )
				{
					damage = 15;
					target.damageCompute(damage);
					mana -=30;
				}
				if(attack == UPPERCUT)
				{
					damage = 15;
					target.damageCompute(damage);
					mana -=30;
				}
			} //attacker is SPECIAL
			if(attack == SPECIAL)
			{
				if(mana >=60)
				{
					damage = 40;
					target.damageCompute(damage);
					mana -=60;
				}
			}
		}
		
	}

	FighterName Fighter::getName()
	{
		return name;
	}
	
	FighterName Fighter::setName(FighterName name)
	{
		this->name = name;
		return name;
	}
	
	int Fighter::getHealthPoints()
	{
		return healthPoints;
	}

	int Fighter::setHealthPoints(int healthPoints)
	{
		this->healthPoints = healthPoints;
		return healthPoints;
	}
	
	int Fighter::setHealthPointsMax(int healthPointsMax)
	{
		this->healthPointsMax = healthPointsMax;
		return healthPointsMax;
	}
	
	int Fighter::getHealthPointsMax()
	{
		return healthPointsMax;
	}
	
	int Fighter::setCombo(int combo)
	{
		this->combo=combo;
		return combo;
	}

	int Fighter::getCombo()
	{
		return combo;
	}
	
	FighterStatus Fighter::setStatus(FighterStatus status)
	{
		this->status = status;
		return status;
	}

	int Fighter::getStatus()
	{
		return status;
	}

	Attack Fighter::setAttack(Attack attak)
	{
		this->attak = attak;
		return attak;
	}
	
	Attack Fighter::getAttack()
	{
		return attak;
	}

	int Fighter::setMovePoints(int movePoints)
	{
		this->movePoints = movePoints;
		return movePoints;
	}

	int Fighter::getMovePoints()
	{
		return movePoints;
	}

	void Fighter::setMana(int mana)
	{
		this->mana = mana;
	}

	int Fighter::getMana()
	{
		return mana;
	}

	void Fighter::recharge(Fighter& fighter)
	{
		fighter.setStatus(RECHARGE);
		int m = fighter.getMana();
		m += 20;
		int h = fighter.getHealthPoints() ;
		h+= 10;
	}

	void Fighter::defend(Fighter& defender)
	{
		defender.setStatus(DEFENSE);
		
	}
	
}
