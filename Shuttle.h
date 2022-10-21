#ifndef SHUTTLE_H
#define SHUTTLE_H
#include <iostream>
#include <string>
#include "Humans.h"
using namespace std;
class Shuttle
{

public:
    Shuttle();
    // Shuttle();
    int getSpaceSuit(); // getters
    int getFuel();
    bool getTranslator();
    int getNumMeds();
    int getMoney();
    int getSpaceSuitHealth();
    string getWeaponAt(int);

    void setSpaceSuit(int); // setters
    void setSpaceSuitHealth(int);
    void setFuel(int);
    void setTranslator(bool);
    void setNumMeds(int);
    void setMoney(int);
    bool setWeaponAt(int, string);
    bool useMed(Humans&);
    void displayInventory();
    bool purchase(int);
    bool addWeapon(string);
    int getNumWeapons();
    bool breakWeapon(string);

private:
    int spaceSuit; // space suit grade
    int spaceSuitHealth;
    int fuel;
    int numSaber;
    bool translator;
    int meds;
    int money;
    int numWeapons;
    int numBeam;
    int numBlaster;
    string weapons[2];
};
#endif