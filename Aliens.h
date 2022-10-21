#ifndef ALIENS_H
#define ALIENS_H

#include <iostream>
using namespace std;

class Aliens
{
    public:
    Aliens();
    Aliens(string,int,bool,int x,int y);
    void setName(string);
    void setHealth(int);
    void setFriend(bool);
    void setPosition(int,int);

    string getName();
    int getHealth();
    bool getFriend();
    string getPosition();
    private:
    int _position[2];
    int _health;
    string _name;
    bool _friendly;
};

#endif