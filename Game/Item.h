/*
All code is property of Andrew Weller and nobody else has permission to call this their own.
For all inquiries - andrewweller.cs@gmail.com
*/

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Character;

using namespace std;
/*
This class represents an Item, which is any item that can be stored in the player's inventory
The player will have an array of items which will represent their inventory.
*/
class Item
{
protected:
	string name;
public:
	Item(string);
	void setName(string);
	string getName();

	virtual string getInfo();
	virtual string getInteraction();
	virtual void interact(Character*);
};
#endif