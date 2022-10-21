#include "Shuttle.h"
//#include "Humans.h"
#include <iostream>
#include <string>
using namespace std;
Shuttle::Shuttle() // defualt constructor
{
    spaceSuitHealth = 100;
    spaceSuit = 1;
    meds = 0;
    numWeapons = 1;
    numSaber = 1;
    numBeam=0;
    numBlaster=0;
    fuel = 200000;
    translator = 0;
    money = 100000;
    weapons[0] = "Light Saber";
    weapons[1] = "";
}
int Shuttle::getFuel() // returns amount of fuel
{
    return fuel;
}
int Shuttle::getMoney() // returns money
{
    return money;
}
int Shuttle::getNumMeds() // returns number of medkits
{
    return meds;
}
int Shuttle::getSpaceSuit() // returns spacesuit grade
{
    return spaceSuit;
}
int Shuttle::getSpaceSuitHealth() // returns health of spacesuit
{
    return spaceSuitHealth;
}
bool Shuttle::getTranslator() // returns if the player has a translator
{
    return translator;
}
string Shuttle::getWeaponAt(int index) // returns weapon at a certain index
{
    if (index == 0 || index == 1)
    {
        return weapons[index];
    }
    else // checks if the index is out of range
    {
        return "out of range";
    }
}

void Shuttle::setFuel(int amount) // sets the fuel value
{
    fuel = amount;
}

void Shuttle::setTranslator(bool have) // declares if the user has a translator
{
    translator = have;
}

void Shuttle::setMoney(int mon) // sets the amount of money the player has
{
    money = mon;
}

void Shuttle::setNumMeds(int medkits) // sets the number of medkits the player has
{
    meds = medkits;
}

void Shuttle::setSpaceSuit(int grade) // sets the grade of the player's spacesuit
{
    spaceSuitHealth=100;
    spaceSuit = grade;
}

void Shuttle::setSpaceSuitHealth(int health) // sets health of the player's spacesuit
{
    spaceSuitHealth = health;
}
bool Shuttle::setWeaponAt(int index, string name) // sets weapon at an index in the weapon array
{
    if (index == 0 || index == 1)
    {
        weapons[index] = name; // overwrites weapon in weapon array
        return true;
    }
    else // checks if array is out of range
    {
        return false;
    }
}
bool Shuttle::useMed(Humans &player)
{
    int currentHp;
    if (meds > 0)
    {
        meds -= 1;
        currentHp = player.getHealth();
        currentHp = currentHp * 1.4;
        if (currentHp > 100)
        {
            currentHp = 100;
        }
        player.setHealth(currentHp);
        // set player health to 100%
        return true;
    }
    else
    {
        return false;
    }
}
void Shuttle::displayInventory()
{
    cout << "- Money - $" << money << endl;
    cout << "- WEAPONS - " << numWeapons << endl;
    cout << "1. Light Saber - " << numSaber << endl;
    cout << "2. Blaster - " << numBlaster << endl;
    cout << "3. Beam gun - " << numBeam << endl;
    cout << "- TRANSLATOR - " << translator << endl;
    cout << "- SPACE SUIT GRADE #" << spaceSuit << endl;
    cout << "- MEDICAL KITS - " << meds << endl;
    cout << "- FUEL - " << fuel << " Gallons" << endl;
}
bool Shuttle::purchase(int cost)
{
    if (cost > money) // checks if the player can afford the item
    {
        return false;
    }
    else
    {
        money -= cost; // updates the current amount of money the player has
        return true;
    }
}
bool Shuttle::addWeapon(string name)
{
    int index = -1;
    if (weapons[0] == "")
    {
        index = 0;
    }
    else if (weapons[1] == "")
    {
        index = 1;
    }
    if (name == "Light Saber" || name == "Blaster" || name == "Beam gun")
    {
        if (index != -1)
        {
            if(name == "Light Saber")
            {
                numSaber++;
            }
            else if (name == "Blaster")
            {
                numBlaster++;
            }
            else if (name == "Beam gun")
            {
                numBeam++;
            }
            weapons[index] = name;
            numWeapons++;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool Shuttle::breakWeapon(string name)
{
    int index = -1;
    if (weapons[0] == name)
    {
        index = 0;
    }
    else if (weapons[1] == name)
    {
        index = 1;
    }
    if (index != -1)
    {
        if(name == "Light Saber")
            {
                numSaber--;
            }
            else if (name == "Blaster")
            {
                numBlaster--;
            }
            else if (name == "Beam gun")
            {
                numBeam--;
            }
        weapons[index] = "";
        numWeapons--;
        return true;
    }
    else
    {
        return false;
    }
}
int Shuttle::getNumWeapons()
{
    return numWeapons;
}