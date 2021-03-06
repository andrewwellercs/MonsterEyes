#include <iostream>

#include "Character.h"

using namespace std;

/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

Character::Character()
{
	name = "NULL";
	gold = 0;
	health = 0;
	maxHealth = 0;
	level = 0;
	xp = 0;
}
/*
Character is a class that will be used to represent:
The player
The enemies.
NPCs
*/
Character::Character(string nameIn, int maxHealthIn)
{
	name = nameIn;
	health = maxHealthIn;
	maxHealth = maxHealthIn;

	level = 1;
	xp = 0;
	gold = 0;


	inventory.reserve(20);
}

int Character::getHealth()
{
	return health;
}
int Character::getMaxHealth()
{
	return maxHealth;
}
void Character::setName(string nameIn)
{
	name = nameIn;
}

string Character::getName()
{
	return name;
}

//setters
//returns true if the player is still alive after changing health
void Character::setHealth(int healthIn)
{
	health = healthIn;
}
//permanently change the players maxHealth
void Character::setMaxHealth(int healthIn)
{
	maxHealth = healthIn;
}

void Character::setGold(int goldIn)
{
	gold = goldIn;
}

int Character::getGold()
{
	return gold;
}

void Character::setXP(int XPIn)
{
	xp = XPIn;
}
int Character::getXP()
{
	return xp;
}

void Character::setLevel(int levelIn)
{
	level = levelIn;
}
int Character::getLevel()
{
	return level;
}

void Character::levelUp()
{
	level++;
	maxHealth += 6;
	health = maxHealth;
}

int Character::getDamageDealt()
{
	if (!wearingFlags[0])
	{
		return 1;
	}
	else
	{
		return rand() % getMaxDamage() + 1;
	}
}

void Character::setMaxDamage(int dmgIn)
{
	maxDamage = dmgIn;
}
int Character::getMaxDamage(){return maxDamage;}


//more getters/setters

vector<Item*>* Character::getInventory()
{
	return &inventory;
}
Equipable** Character::getWearing()
{
	return wearing;
}
void Character::setWearing(int i, bool b)
{
	wearingFlags[i] = b;
}

bool Character::isWearing(int i)
{
	return wearingFlags[i];
}

bool Character::alive()
{
	return health > 0;
}

void Character::createWearingItem(Equipable* item)
{
	wearingFlags[item->getSlot()] = true;
	wearing[item->getSlot()] = item;

	cout << this->getWearing()[4]->getName() << endl;
}
