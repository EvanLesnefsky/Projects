#include "Aliens.h"
#include <vector>
#ifndef PLANETS_H
#define PLANETS_H

#include <iostream>

using namespace std;

class Planets
{
    public:
    Planets();
    Planets(string,bool,int,int,int,double,vector<Aliens>);
    string getName();
    bool isHabitable();
    int getCapacity();
    int getNumAliens();
    int getNumSites();
    Aliens getAlienAt(int);
    double getSize();
    string getGoodTraits();
    string getBadTraits();
    int getPlayerReport();

    void setName(string);
    void setHabitable();
    void setCapacity(int);
    void setNumAliens(int);
    void setNumSites(int);
    void setSize(double);
    void setAlienList(vector<Aliens>);
    void setPlayerReport(int);
    void playerFound(int);
    bool hasFound(int);
    bool hasMadeContact();
    void setMadeContact();
    string getTrait();

    private:
    string _name;
    bool _habitable;
    int _capacity;
    int _numAliens;
    int _numSites;
    double _size;
    int _playerReport;
    
    //water,oxygen,fertile soil,toxic gas,bad atmosphere,extreme temperatures
    bool found[6]={false,false,false,false,false,false};
    bool madeContact;
    vector<Aliens> _aliensList;
    vector<string> unFoundTraits;
    vector<string> goodTraits;
    vector<string> badTraits;
};

#endif