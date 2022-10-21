//#include "Planets.h"
#include "Game.h"
//#include "planets.cpp"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*
1. Compare the letters in each word. 
2. Return true if it is a letter and a smaller ascii value than the letters of the word being compared.
3. Repeat the steps for all words. 
*/
void statusBars(int hp, int totHp,int ssHp,int totssHp,int fuel,int totFuel)
{
    string arr[3]={"Health:","Space Suit Health:","Fuel tank:"};
    int val[3]={hp,ssHp,fuel};
    int max[3]={totHp,totssHp,totFuel};
    double percent;
    for(int i = 0;i<3;i++)
    {
        percent=double(val[i])/max[i]*100;
        cout << arr[i]<<endl;
        for (int j = 1;j<=20;j++)
        {
            if(percent>=j*5)
            {
                cout << "_";
            }
            else{
                cout << " ";
            }
        }
        cout << " "<<percent<<"%"<<endl;
    }
}
bool comesBefore(string text1, string text2)
{
    char letter1;
    char letter2;
    for (int i = 0; i < text1.length(); i++) // loop until the size of the word and iterate by 1
    {
        letter1 = tolower(text1[i]); // setting the variables equal to the words
        letter2 = tolower(text2[i]); // make it case insensitive
        if (int(letter2) < 97) // if the word is not a letter
        {
            return false;
        }
        if (int(letter1) > int(letter2)) // if the first word is greater than the second
        {
            return false;
        }
        else if (int(letter1) < int(letter2)) // if the first word is less than the second word
        {
            return true;
        }
        else if (int(letter1) == int(letter2)) // if the words are equal in value
        {
            continue;
        }
    }
    return true;
}

Game::Game()
{
    log = {}; // vector for planets
    humansPerished=0;
    humansSaved=0;
    correctReports=0;
    incorrectReports=0;
}
void Game::addPlanet(Planets Planet)
{
    log.push_back(Planet); // push back planet to the vector string
}

int Game::planetIndex(string name)
{
    for (int i = 0; i < log.size(); i++) // loop until the size of the vector and iterate by 1
    {
        if (name == log[i].getName()) // if the name is equal to the name in the vector
        {
            return i; // return the index at that point
        }
    }
    return -1; // end
}

void Game::displayLog()
{
    for (int i = 0; i < log.size(); i++) // loop until the size of the vector and iterate by 1
    {
        cout << log[i].getName(); // print each planet name
        if (log[i].isHabitable()) // if the planet is habitable
        {
            cout << " is habitable." << endl;
        }
        else // if the planet is not habitable
        {
            cout << " is not habitable." << endl;
        }
    }
}

/*
1. Compares each planet name. 
2. Creates a temp variable for the planet names.
3. If the vector is empty then add a planet.
4. Otherwise, run a for loop that increments down and checks each word to check if the word is smaller than the last.
5. Sorts each planet name alphabetically.
6. Displays each planet in the correct order.
*/

void Game::sortLog()
{
    int len = log.size();
    vector<Planets> temp; // vector
    Planets tempPlanet; // planet object
    string name = ""; // start with empty string
    for (int i = 0; i < len; i++) // loop until the size of the vector
    {
        tempPlanet = log[i]; // set the temp variable equal to each planet name
        name = tempPlanet.getName(); // set each name equal to the planets
        if (temp.size() == 0) // if the vector is empty
        {
            temp.push_back(tempPlanet); // add the planet to the vector
            continue;
        }
        else
        {
            for (int j = temp.size() - 1; j >= 0; j--) // start at the size of the vector -1 and increment down until it is empty
            {
                if (j == 0 && comesBefore(name, temp[j].getName())) // if the index is 0 and the first name is smaller than the second name
                {
                    temp.insert(temp.begin(), tempPlanet); // insert the name at the beginning of the vector
                    break;
                }
                if (comesBefore(name, temp[j].getName())) // if only the name is smaller than the second name
                {
                    continue;
                }
                else
                {
                    temp.insert(temp.begin() + j + 1, tempPlanet); // insert the planet that is smaller at the index plus 1 to fit the size of the vector
                    break;
                }
            }
        }
    }
    for (int i = 0; i < temp.size(); i++) // loop until it reaches the size of the vector and increment by 1
    {
        log[i] = temp[i]; // display each planet alphabetically 
    }
}
int Game::planetsExplored()
{
    return log.size();//returns number of planets in the logbook which is the planets explored
}
int Game::getHumansPerished()
{
    return humansPerished;
}
int Game::getHumansSaved()
{
    return humansSaved;
}
void Game::morePerished(int more)
{
    humansPerished+=more;
}
void Game::moreSaved(int more)
{
    humansSaved+=more;
}
void Game::viewStatus(Shuttle shuttle,Humans player)
{
    statusBars(player.getHealth(),100,shuttle.getSpaceSuitHealth(),100,shuttle.getFuel(),400000);
    cout << "Planets explored: " << log.size()<<endl;
    int correctReports=0;
    int incorrectReports=0;
    for (int i = 0;i<log.size();i++)
    {
        if (log[i].isHabitable()==log[i].getPlayerReport())
        {
            correctReports++;
        }
        else if(log[i].getPlayerReport()==-1)
        {
            continue;
        }
        else
        {
            incorrectReports++;
        }
    }
    cout << "Planets accurately reported habitable: "<<correctReports<<endl;
    cout << "Planets inaccurately reported habitable: "<<incorrectReports<<endl;
    cout << "Humans saved (in millions): "<<humansSaved<<endl;
    cout << "Humans perished (in millions): "<<humansPerished<<endl;
    shuttle.displayInventory();
}
void Game::displayLogCurrent()
{
    Planets currentPlanet = log.back();
    Humans player =crew[0];
    bool flag=true;
    string good[3]={"Water","Oxygen","Fertile Soil"};
    string bad[3]={"Toxic gas","Bad atmosphere","Exetreme temperature"};
    cout << player.getName()<<"'s Log Book page #"<<log.size()<<": "<<currentPlanet.getName()<<endl;
    cout << "Planet size (in diameter of 1000 kms): "<<currentPlanet.getSize()<<endl;
    cout << "Planet’s carrying capacity (in millions): " <<currentPlanet.getCapacity()<<endl;
    cout << "Habitable traits discovered: ";
    for (int i = 1;i<=3;i++)
    {
        if(currentPlanet.hasFound(i))
        {
            if(flag)
            {
                cout << good[i-1];
                flag=false;
            }
            else
            {
                cout << ", "<<good[i-1];
            }
        }
    }
    if (flag)
    {
        cout << "None";
    }
    flag=true;
    cout<<endl;
    cout << "Non-habitable traits discovered: "; 
    for (int i = 1;i<=3;i++)
    {
        if(currentPlanet.hasFound(i+3))
        {
            
            if(flag)
                {
                    cout << bad[i-1];
                    flag=false;
                }
                else
                {
                    cout << ", "<<bad[i-1];
                }
        }
    }
    if (flag)
    {
        cout << "None";
    }
    cout<<endl;
    cout << "Friendly alien assessment: ";
    if(currentPlanet.hasMadeContact())
    {
        if(currentPlanet.isHabitable())
        {
            cout << "Habitable"<<endl;
        }
        else
        {
            cout << "Non-habitable"<<endl;
        }
    }
    else{
        cout << "None"<<endl;
    }
}
void Game::setCrew(Humans &player,Humans &crew1,Humans &crew2)
{
    crew[0]=player;
    crew[1]=crew1;
    crew[2]=crew2;
}
void Game::setCurrentPlanet(Planets planet)
{
    log.back()=planet;
}
Planets Game::getCurrentPlanet()
{
    return log.back();
}
bool Game::saveLog(string filename)
{   
    ofstream fout;
    if(fout.fail())
    {
        return 0;
    }
    fout.open(filename);
    Planets currentPlanet;
    Humans player =crew[0];
    string good[3]={"Water","Oxygen","Fertile Soil"};
    string bad[3]={"Toxic gas","Bad atmosphere","Exetreme temperature"};
    bool flag=false;
    for (int i=0;i<log.size();i++)
    {
        currentPlanet=log[i];
        fout << player.getName()<<"'s Log Book page #"<<i+1<<": "<<currentPlanet.getName()<<endl;
        fout << "Planet size (in diameter of 1000 kms): "<<currentPlanet.getSize()<<endl;
        fout << "Planet’s carrying capacity (in millions): " <<currentPlanet.getCapacity()<<endl;
        fout << "Habitable traits discovered: ";
        for (int i = 1;i<=3;i++)
        {
            if(currentPlanet.hasFound(i))
            {
                if(i==1)
                {
                    fout << good[i-1];
                }
                else
                {
                    flag=true;
                    fout << ", "<<good[i-1];
                }
            }
        }
        if (!flag)
        {
            fout << "None";
            flag=false;
        }
        fout<<endl;
        fout << "Non-habitable traits discovered: "; 
        for (int i = 4;i<=6;i++)
        {
            if(currentPlanet.hasFound(i))
            {
                if(i==4)
                    {
                        fout << bad[i-1];
                    }
                    else
                    {
                        flag=true;
                        fout << ", "<<bad[i-1];
                    }
            }
        }
        if (!flag)
        {
            fout << "None";
            flag=false;
        }
        fout<<endl;
        fout << "Friendly alien assessment: ";
        if(currentPlanet.hasMadeContact())
        {
            if(currentPlanet.isHabitable())
            {
                fout << "Habitable"<<endl;
            }
            else
            {
                fout << "Non-habitable"<<endl;
            }
        }
        else{
            fout << "None"<<endl;
        }
    }
    fout.close();
    return 1;
}
int Game::getCorrectReports()
{
    return correctReports;
}
int Game::getIncorrectReports()
{
    return incorrectReports;
}
void Game::addCorrectReports()
{
    correctReports++;
}
void Game::addIncorrectReports()
{
    incorrectReports++;
}
char Game::getCrewAblilty(int index)
{
    return crew[index].getAttributes();
}
int Game::getLogSize()
{
    return log.size();
}