#ifndef GAME_H
#define GAME_H
#include "Planets.h"
#include "Humans.h"
#include "Shuttle.h"
#include <vector>
#include <iostream>

class Game
{
    public:
    Game();
    void addPlanet(Planets);
    void displayLog();
    void sortLog();
    void displayLogCurrent();
    int planetIndex(string);
    int planetsExplored();
    int getHumansSaved();
    int getHumansPerished();
    void moreSaved(int);
    void morePerished(int);
    void viewStatus(Shuttle,Humans);
    void setCrew(Humans&,Humans&,Humans&);
    void setCurrentPlanet(Planets);
    Planets getCurrentPlanet();
    bool saveLog(string);
    int getCorrectReports();
    int getIncorrectReports();
    void addCorrectReports();
    void addIncorrectReports();
    int getLogSize();
    char getCrewAblilty(int);
    

    private:
    int humansSaved;
    int humansPerished;
    int correctReports;
    int incorrectReports;
    vector<Planets> log;
    Humans crew[3]; 
};

#endif