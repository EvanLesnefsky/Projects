// CSCI1300 Spring 2022
// Author: Evan Lesnefsky
// Recitation: 103 - Rahul Kumar
// Project 2 Part 1 - Problem #1 - Movie.cpp

#include <iostream>
#include <string>
#include "Humans.h"

using namespace std;

Humans::Humans()
{ // setting the default values to ""
    name = "";
    attributes = 0;
}
Humans::Humans(string _name, int _health, int _attributes)
{ // parameterized constructor
    name = _name;
    health = _health;
    attributes = _attributes;
}

string Humans::getName()
{ // returns the name
    return name;
}

int Humans::getHealth()
{ // returns the health
    return health;
}

char Humans::getAttributes()
{
    return attributes;
}

void Humans::setName(string str)
{ // sets the name
    name = str;
}

void Humans::setHealth(int hp)
{
    health = hp;
}

void Humans::setAttributes(char num)
{
    attributes = num;
}