#include "Aliens.h"
#include <string>
#include <iostream>
using namespace std;

Aliens::Aliens()
{
    _name="";
    _health=100;
    _friendly=1;
    _position[0]=0;
    _position[1]=0;
}
Aliens::Aliens(string name,int hp,bool friendly,int x,int y)
{
    _name=name;
    _health=hp;
    _friendly=friendly;
    if (x != -1)
    {
        _position[0]=x;
    }
    if (y != -1)
    {
        _position[1]=y;
    }
}
void Aliens::setName(string name)
{
    _name=name;
}
void Aliens::setHealth(int hp)
{
    _health=hp;
}
void Aliens::setFriend(bool friendly)
{
    _friendly=friendly;
}
void Aliens::setPosition(int x,int y)
{
    if(x != -1)
    {
        _position[0]=x;
    }
    if(y != -1)
    {
        _position[1]=y;
    }
}

string Aliens::getName()
{
    return _name;
}
int Aliens::getHealth()
{
    return _health;
}
bool Aliens::getFriend()
{
    return _friendly;
}
string Aliens::getPosition()
{
    return to_string(_position[0])+","+to_string(_position[1]);
}