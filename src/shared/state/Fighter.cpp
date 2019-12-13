#include "Fighter.h"
#include <iostream>

using namespace std;

namespace state{


	Fighter:: Fighter()
	{
		
	}

	Fighter:: Fighter(int playerID, FighterName name)
	{
		this-> playerID = playerID;
		this-> name = name;
	}


	Fighter::Fighter(FighterName name, int playerID, FighterStatus status, int healthPointsMax, int healthPoints,int movePoints,int combo,Attack attack, int mana)
	{
		this->name = name;
		this->playerID = playerID;
		this->status = status;
		this->healthPointsMax = healthPointsMax;
		this->healthPoints = move(healthPoints);
		this->combo=combo;
		this->attack=attack;
		this->mana = move(mana);
	}
	
	int Fighter::damageCompute(int damage)
	{	
		this->healthPoints = move(healthPoints - damage);
		if(healthPoints <0) 
		{
			healthPoints=0;
		}
		return healthPoints;
	}

	

void Fighter::fight(std::shared_ptr<Fighter> target, Attack attack)
{
	int damage =0;
	if(mana >=30)
	{
		//cout << "enough mana" << endl;
		if(target->getStatus()!=DEFENSE)
		{
			if(attack==COUPDEPOING )
			{
				damage = 20;		//for defining the variable
				target->damageCompute(damage); // attack in Fighter
				mana -= 30;
				status = ATTACK;
			}
			if(attack==COUPDEPIED )
			{
				damage = 30;
				target->damageCompute(damage);
				mana -= 40;
				//status = WAITING;
			}
		}
		else if(target->status == DEFENSE)
		{
			if(attack == COUPDEPOING)
			{
				damage = 10;
				target->damageCompute(damage);
				mana -=30;
				status = ATTACK;
			}
			if(attack == COUPDEPIED )
			{
				damage = 20;
				target->damageCompute(damage);
				mana -=40;
				//status = WAITING;
			}
		} 
		if(attack == SPECIAL)
		{
			if(mana >=60)
			{
				damage = 60;
				target->damageCompute(damage);
				mana -=70;
				//status = WAITING;
			}else{
				cout << "not enough mana for special attack. Please recharge! ;) "<<endl; 
				status = WAITING;
			}
		}
	}else{
		cout << "Please recharge! ;)" << endl;
	}
	
}

	FighterName Fighter::getName()
	{
		return name;
	}
	
	void Fighter::setName(FighterName name)
	{
		this->name = name;
	}
	
	int Fighter::getHealthPoints()
	{
		return healthPoints;
	}

	void Fighter::setHealthPoints(int healthPoints)
	{
		this->healthPoints = healthPoints;
	}
	
	void Fighter::setHealthPointsMax(int healthPointsMax)
	{
		this->healthPointsMax = healthPointsMax;
	}
	
	int Fighter::getHealthPointsMax()
	{
		return healthPointsMax;
	}
	
	void Fighter::setCombo(int combo)
	{
		this->combo=combo;
	}

	int Fighter::getCombo()
	{
		return combo;
	}
	
	void Fighter::setStatus(FighterStatus status)
	{
		this->status = status;
	}

	FighterStatus Fighter::getStatus()
	{
		return status;
	}

	void Fighter::setAttack(Attack attack)
	{
		this->attack = attack;
	}
	
	Attack Fighter::getAttack()
	{
		return attack;
	}

	void Fighter::setMana(int mana)
	{
		this->mana = mana;
	}

	int Fighter::getMana()
	{
		return mana;
	}

	void Fighter::recharge()
	{
		mana += 20;
		if(mana>manaMax) mana = manaMax;
	}

	void Fighter::defend()
	{
		status = DEFENSE;
	}
	
}

std::shared_ptr<state::Fighter> state::Fighter::copy()
{
	std::shared_ptr<Fighter> result = std::make_shared<Fighter>();
	result->status = status;
	result->x = x;
	result->y = y;
	result->name = name;
	result->status = status;
	result->healthPointsMax = healthPointsMax;
	result->healthPoints = healthPoints;
	result->manaMax = manaMax;
	result->mana = mana;
	result->combo = combo;
	result->attack = attack;
	return result;
}