#ifndef HUMANS_H
#define HUMANS_H

#include <iostream>
#include <string>
using namespace std;

class Humans
{
public:
    Humans();
    Humans(string name, int health, int attributes);
    void setName(string);
    void setHealth(int);
    void setAttributes(char);
    string getName();
    int getHealth();
    char getAttributes();

private: // defining the variables
    int health = 100;
    string name;
    char attributes;
    // int Xpos;
    // int Ypos;
};

#endif