#include "Fighter.h"
#include <iostream>

using namespace std;

namespace state{

	Fighter:: Fighter()
	{

	}

	Fighter::Fighter(FighterName name, FighterStatus status, int healthPointsMax, int healthPoints,int movePoints,int combo,Attack attak)
	{
		this->name = name;
		this->status = status;
		this->healthPointsMax = healthPointsMax;
		this->healthPoints = healthPoints;
		this->combo=combo;
		this->attak=attak;
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
		if(attack==COUPDEPOING && target.status!=DEFENSE)
		{
			attak = COUPDEPOING; //attak is the value uses 
			damage = 20;		//for defining the variable
			target.damageCompute(damage); // attack in Fighter
			
		}
		if(attack==COUPDEPIED && target.status!=DEFENSE)
		{
			attak = COUPDEPIED;
			damage = 20;
			target.damageCompute(damage);
		}
		if(attack==UPPERCUT && target.status!=DEFENSE)
		{
			attak = UPPERCUT;
			damage = 30;
			target.damageCompute(damage);
		}
				
		if(attack==FLASH_KICK && target.status!=DEFENSE)
		{
			attak = FLASH_KICK;
			damage = 30;
			target.damageCompute(damage);
		}
		//target defending
		if(target.status == DEFENSE)
		{
			if(attack == COUPDEPOING )
			{
				damage = 10;
				target.damageCompute(damage);
			}
			if(attack == COUPDEPIED )
			{
				damage = 10;
				target.damageCompute(damage);
			}
			if(attack == FLASH_KICK )
			{
				damage = 15;
				target.damageCompute(damage);
			}
			if(attack == UPPERCUT)
			{
				damage = 15;
				target.damageCompute(damage);
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
}
