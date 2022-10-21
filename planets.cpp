#include "Planets.h"
#include <time.h>
#include <vector>
#include <iostream>

using namespace std;
Planets::Planets()
{
    _name="defualt";
    _habitable=1;
    _capacity=10;
    _numAliens=1;
    _numSites=1;
    _size=0;
    _playerReport=-1;
    madeContact=false;
    srand(time(NULL));   
    int precent=rand()%100;
    if(precent>=40)
    {
        goodTraits={"Water","Oxygen","Fertile Soil"};
    }
    else if(precent>=15)
    {
        goodTraits={"Water","Oxygen"};
    }
    else if (precent>=5)
    {
        goodTraits={"Water"};
    }
    else
    {
        goodTraits={};
    }
    //srand(time(NULL));
    precent = (precent*rand())%100;
    if(precent>=75)
    {
        badTraits={"Toxic Gas","Bad Atmosphere","Extreme Temperatures"};
    }
    else if(precent>=55)
    {
        badTraits={"Toxic Gas","Bad Atmosphere"};
    }
    else if (precent>=30)
    {
        badTraits={"Toxic Gas"};
    }
    else
    {
        badTraits={};
    }
    if (badTraits.size()+goodTraits.size()==0)
    {
        if(rand()%6>=3)
        {
            badTraits={"Bad Atmosphere"};
        }
        else
        {
            goodTraits={"Oxygen"};
        }
    }
    if (goodTraits.size() != 3)
    {
       _habitable=false;

    }
    else if (badTraits.size() > 1)
    {
        _habitable=false;
    }
    else
    {
        _habitable=true;
    }
    unFoundTraits=goodTraits;
    vector<string> temp = badTraits;
    for (int i = 0; i<badTraits.size();i++)
    {
        unFoundTraits.push_back(temp.back());
        temp.pop_back();
    }

}
Planets::Planets(string name,bool habitable,int capacity,int numAliens,int numSites,double size,vector<Aliens> aliensList)
{
    _name=name;
    _habitable=habitable;
    _capacity=capacity;
    _numAliens=numAliens;
    _numSites=numSites;
    _aliensList=aliensList;
    _playerReport=-1;
    madeContact=false;
    srand(time(NULL));
    int precent=rand()%100;
    if(precent>=40)
    {
        goodTraits={"Water","Oxygen","Fertile Soil"};
    }
    else if(precent>=15)
    {
        goodTraits={"Water","Oxygen"};
    }
    else if (precent>=5)
    {
        goodTraits={"Water"};
    }
    else
    {
        goodTraits={};
    }
    //srand(time(NULL));
    precent = (precent*rand())%100;
    if(precent>=75)
    {
        badTraits={"Toxic Gas","Bad Atmosphere","Extreme Temperatures"};
    }
    else if(precent>=55)
    {
        badTraits={"Toxic Gas","Bad Atmosphere"};
    }
    else if (precent>=30)
    {
        badTraits={"Toxic Gas"};
    }
    else
    {
        badTraits={};
    }
    if (badTraits.size()+goodTraits.size()==0)
    {
        if(rand()%6>=3)
        {
            badTraits={"Bad Atmosphere"};
        }
        else
        {
            goodTraits={"Oxygen"};
        }
    }
    if (goodTraits.size() != 3)
    {
       _habitable=false;

    }
    else if (badTraits.size() > 1)
    {
        _habitable=false;
    }
    else
    {
        _habitable=true;
    }
}
Aliens Planets::getAlienAt(int index)
{
    return _aliensList[index];
}
double Planets::getSize()
{
    return _size;
}
void Planets::setSize(double size)
{
    _size=size;
}
void Planets::setAlienList(vector<Aliens> aliensList)
{
    _aliensList=aliensList;
}
string Planets::getName()
{
    return _name;
}
bool Planets::isHabitable()
{
    return _habitable;
}
int Planets::getCapacity()
{
    return _capacity;
}
int Planets::getNumAliens()
{
    return _numAliens;
}
int Planets::getNumSites()
{
    return _numSites;
}
void Planets::setName(string name)
{
    _name=name;
}
void Planets::setHabitable()
{
    if (goodTraits.size() != 3)
    {
       _habitable=false;

    }
    else if (badTraits.size() > 1)
    {
        _habitable=false;
    }
    else
    {
        _habitable=true;
    }
}
void Planets::setCapacity(int capacity)
{
    _capacity=capacity;
}
void Planets::setNumAliens(int numAliens)
{
    _numAliens=numAliens;
}
void Planets::setNumSites(int numSites)
{
    _numSites=numSites;
}
string Planets::getGoodTraits()
{
    string temp="";
    for(int i = 0;i<goodTraits.size();i++)
    {   
        if (i == goodTraits.size()-1)
        {
            temp+=goodTraits[i];
            break;
        }
        temp+=(goodTraits[i]+",");
    }
    return temp;
}
string Planets::getBadTraits()
{
    string temp="";
    for(int i = 0;i<badTraits.size();i++)
    {
        if (i == badTraits.size()-1)
        {
            temp+=badTraits[i];
            break;
        }
        temp+=(badTraits[i]+",");
    }
    return temp;
}
int Planets::getPlayerReport()
{
    //cout << "Player report is"<<_playerReport<<endl;
    return _playerReport; 
}
void Planets::setPlayerReport(int report)
{
    //cout << "Player report set to:"<<report<<endl;
    _playerReport=report;
}
bool Planets::hasFound(int place)
{
    return found[place-1];
}
void Planets::playerFound(int place)
{
    found[place-1]=true;
}
bool Planets::hasMadeContact()
{
    return madeContact;
}
void Planets::setMadeContact()
{
    madeContact=true;
}
string Planets::getTrait()
{
    string traits[6]={"Water","Oxygen","Fertile Soil","Toxic Gas","Bad Atmosphere","Extreme Temperatures"};
    int total = unFoundTraits.size()-1;
    int index;
    string trait;
    srand(time(NULL));
    if (total == -1)
    {
        return "no other unique traits";
    }
    else if (total != 0)
    {
        index = rand()%total;
    }
    else 
    {
        index =0;
    }
    trait=(string)unFoundTraits.at(index);
    unFoundTraits.erase(unFoundTraits.begin()+index);
    return trait;
    // if (index < goodTraits.size())
    // {
    //     trait =goodTraits[index];
    // }
    // else
    // {
    //     trait = badTraits[index-goodTraits.size()];
    // }
    // for(int i = 0;i<6;i++)
    // {
    //     if(trait==traits[i])
    //     {
    //         found[i]=true;
    //         break;
    //     }
    // }
    // return trait;
}