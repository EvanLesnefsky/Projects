#include "Planets.h"
#include "Aliens.h"
#include "Game.h"
#include "Humans.h"
#include "Shuttle.h"
#include "Map.h"
#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
/* Algorithm validates numerical input
1.accepts max, min, string and expected number of digits
2.iterates through string and converts each char to in if possible without throwing an error
3.returns true or false depending if the condition is met
*/
bool isValidInput(string input, int min, int max, int digits)
{
    int number = 0;
    if (input.length() > digits || !(isdigit(input[0])))//checks if input is too long or first chr is not a int
    {
        return false;
    }
    else if (stoi(input) <= max && stoi(input) >= min)//becase the first char is an int it is know that stoi will no longer throw an error, special case for digits > 1
    {
        return true;
    }
    else
    {
        if ((int)input[0] - 48 > max || (int)input[0] - 48 < min)//checks for general case if other cases do not apply
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

int split(string text, char separator, string arr[], int size)
{
    int textLen = text.length();
    int counter = 0;
    if (textLen == 0)
    { // if the string is empty return 0
        return 0;
    }
    for (int i = 0; i < textLen; i++)
    {
        if (counter == size)
        { // if there are too many seperators and not enough instances of arr[]
            return -1;
        }
        if (separator == text[i])
        { // if there is a seperator char move the indexing of arr up by one
            counter++;
        }
        else
        {
            arr[counter] += text[i]; // appends all other characters of text to the index of arr determined by the amount of seperators
        }
    }
    return counter + 1;
}
/*Algorthim: prints out user stats, writes log book to file and terminates program 
1.accepts int dictating the circumstace of the game over
2.prints out specific meassage for each case
3.runs sortLog to sort log
4.uses save log to write to "output.txt"
5.calculates score and stats and prints them
6.terminates program
*/
void gameOver(int result, Game game)
{
    int score;
    switch (result)//follows github instructs for print statements based on cause of game over
    {
    case 1:
        cout << "You have died due to health loss." << endl;
        cout << "Had you planned better with more sophisticated materials, you may have been able to prevent this." << endl;
        cout << "You can no longer explore more of space." << endl;
        break;
    case 2:
        cout << "It is disappointing to hear that you have quit, humanity was depending on you." << endl;
        break;
    case 3:
        cout << "All of humanity has left Earth! Your mission is over." << endl;
        break;
    default:
        break;
    }
    game.sortLog();//sorts log book alphabetically
    game.saveLog("output.txt");//writes logbook to a file
    score = (((double)game.getHumansSaved() - (double)game.getHumansPerished()) / 8000.00 * ((double)game.getCorrectReports()) / ((double)game.getLogSize())) * 100.00;//calculates score
    cout << "Here is a summary of how you did:" << endl;
    cout << "Planets explored: " << game.getLogSize() << endl;
    cout << "Planets accurately reported: " << game.getCorrectReports() << endl;
    cout << "Planets inaccurately reported: " << game.getIncorrectReports() << endl;
    cout << "Humans saved (in millions): " << game.getHumansSaved() << endl;
    cout << "Humans perished (in millions): " << game.getHumansPerished() << endl;
    cout << "TOTAL SCORE: " << score << endl;
    if (score != 100)//if score is below perfect will print this message
    {
        cout << "Play again to see if you can do better!" << endl;
    }
    exit(EXIT_SUCCESS);//terminates program
}
void dead(Humans player, Shuttle shuttle, Game game)
{
    if (player.getHealth() <= 0 || shuttle.getSpaceSuitHealth() <= 0)
    {
        gameOver(2, game);
    }
}
// g++ mainDriver2Electricboogaloo.cpp aliens.cpp game.cpp humans.cpp shuttle.cpp map.cpp planets.cpp
/*Algorithm:splits string into different indexs of array based on appearances of the a seperator character
1.accepts text, seperator,arr[], and size
2.finds length of the text
3.returns 0 if the string is empty
4.iterates through text appending each character of the text to an index of arr
5.checks if character in text is the seperatr character, if so move to the next index of array
6.returns counter + 1
*/
string readAliens(Aliens &alien)
{
    ifstream fin; // for reading information from data files

    fin.open("alien_names.txt"); // opens the file

    if (fin.fail()) // if the file is not opened correctly
    {
        cout << "Could not open file." << endl;
        return "";
    }

    string line; // the words in the file
    string alienName;
    int number = rand() % 20;
    int numberLines = 0; // start at 0 so it doesn't keep adding
    if (fin.is_open())   // if the file is open
    {
        for (int i = 0; i < number; i++)
        {
            getline(fin, line);
        }
        alien.setName(line);
    }
    fin.close(); // close the file
    return line; // end the program
}

Map createMap(Map &mapInstance1)
{

    int npcCount1;
    int npcCount2;
    npcCount1 = rand() % 11;
    npcCount2 = rand() % 11;
    mapInstance1.spawnNPC(npcCount1, npcCount2);

    int site1;
    int site2;
    int site3;
    int site4;
    int site5;
    int site6;
    int site7;
    int site8;
    int site9;
    int site10;
    int site11;
    int site12;
    int site13;
    int site14;
    site1 = rand() % 11;
    site2 = rand() % 11;
    site3 = rand() % 11;
    site4 = rand() % 11;
    site5 = rand() % 11;
    site6 = rand() % 11;
    site7 = rand() % 11;
    site8 = rand() % 11;
    site9 = rand() % 11;
    site10 = rand() % 11;
    site11 = rand() % 11;
    site12 = rand() % 11;
    site13 = rand() % 11;
    site14 = rand() % 11;
    mapInstance1.spawnSite(site1, site2, 1);
    mapInstance1.spawnSite(site3, site4, 2);
    mapInstance1.spawnSite(site5, site6, 3);
    mapInstance1.spawnSite(site7, site8, 4);
    mapInstance1.spawnSite(site9, site10, 5);
    mapInstance1.spawnSite(site11, site12, 6);
    mapInstance1.spawnSite(site13, site14, 2);

    int hA1;
    int hA2;
    int hA3;
    int hA4;
    int misCount6;
    int misCount7;
    int misCount8;
    int misCount9;
    int misCount10;
    int misCount11;

    hA1 = rand() % 11;
    hA2 = rand() % 11;
    hA3 = rand() % 11;
    hA4 = rand() % 11;

    mapInstance1.spawnMisfortune(hA1, hA2, 1); // spawning hostil aliens
    mapInstance1.spawnMisfortune(hA3, hA4, 1);

    int mis1 = rand() % (4 - 2 + 1) + 2;
    int mis2 = rand() % (4 - 2 + 1) + 2;
    int mis3 = rand() % (4 - 2 + 1) + 2;

    misCount6 = rand() % 11;
    misCount7 = rand() % 11;
    misCount8 = rand() % 11;
    misCount9 = rand() % 11;
    misCount10 = rand() % 11;
    misCount11 = rand() % 11;
    mapInstance1.spawnMisfortune(misCount6, misCount7, mis1);
    mapInstance1.spawnMisfortune(misCount8, misCount9, mis2);
    mapInstance1.spawnMisfortune(misCount10, misCount11, mis3);

    return mapInstance1;
}

Map randomMap()
{
    Map map1;
    return createMap(map1);
}

void rpsGame(Shuttle &shuttle)
{
    int player_choice; // choice for the rock paper scissors game

    int win = 0;
    int lose = 0;
    int npc_choice = 0;

    while (win != 3 && lose != 3)
    {
        cout << "Choose: rock(1), paper(2) or scissors(3)" << endl;
        cin >> player_choice; // getting input
        npc_choice = rand() % (3 - 1 + 1) + 1;
        // going through all the scenarios of the game to see who won
        if (player_choice == 1 && npc_choice == 1)
        {
            cout << "You both chose rock, it's a tie." << endl;
        }
        else if (player_choice == 2 && npc_choice == 2)
        {
            cout << "You both chose paper, it's a tie." << endl;
        }
        else if (player_choice == 3 && npc_choice == 3)
        {
            cout << "You both chose scissors, it's a tie." << endl;
        }
        else if (player_choice == 1 && npc_choice == 2)
        {
            cout << "Your opponent chose paper, paper beats rock so you lose this round." << endl;
            lose++;
        }
        else if (player_choice == 1 && npc_choice == 3)
        {
            cout << "Your opponent chose scissors, rock beats scissors so you win this round!" << endl;
            win++;
        }
        else if (player_choice == 2 && npc_choice == 1)
        {
            cout << "Your opponent chose rock, paper beats rock so you win this round!" << endl;
            win++;
        }
        else if (player_choice == 3 && npc_choice == 1)
        {
            cout << "Your opponent chose rock, rock beats scissor so you lose this round." << endl;
            lose++;
        }
        else if (player_choice == 2 && npc_choice == 3)
        {
            cout << "Your opponent chose scissors, scissors beats paper so you lose this round." << endl;
            lose++;
        }
        else if (player_choice == 3 && npc_choice == 2)
        {
            cout << "Your opponent chose paper, scissor beats paper so you win this round!" << endl;
            win++;
        }
        else
        {
            cout << "Re-enter a valid option." << endl;
        }
    }

    if (win == 3)
    { // if the player won reduce frustration
        shuttle.setMoney(shuttle.getMoney() + 200);
        cout << "Congratulations! You defeated the alien and won $200" << endl;
    }
    if (lose == 3)
    {
        cout << "You failed to deafeat the alien! You don't get any money or intel." << endl;
    }
}

void trivia(Humans &player, Planets &planet, Shuttle shuttle, Game game)
{
    int question = rand() % 86;
    int counter = 0;
    string fullLine,correct,line[2],answer[4];
    vector<string> vectAnswer;
    ifstream fin;
    srand(time(NULL));
    fin.open("questions.txt");
    if (fin.fail())
    {
        cout << "Couldn't open file" << endl;
    }
    while (!fin.eof())
    {
        getline(fin, fullLine);
        if (counter == question)
        {
            break;
        }
        counter++;
    }
    split(fullLine,';',line,2);
    split(line[1],',',answer,4);
    char answer_1;
    bool negative = false;
    cout << "Good job, you have found a site that may have some useful information about this planet. If you get this question right, the information will be revealed. If you answer incorrectly though, you'll become more frustrated and lose 1% health due to stress." << endl;
    double reduceHealth = player.getHealth() * 0.01;
    double totalReduceHealth = player.getHealth() - reduceHealth;
    cout << line[0]<<endl;
    correct=answer[0];
    for (int i = 0; i < 4;i++)
    {
        vectAnswer.push_back(answer[i]);
        //cout << vectAnswer.back() <<endl;
    }
    for (int i = 0; i < 4;i++)
    {
        cout << i+1<<".";
        if ((rand()%2)==0)
        {
            cout << vectAnswer.back()<<endl;
            answer[i]=vectAnswer.back();
            vectAnswer.pop_back();
        }
        else 
        {
            cout << vectAnswer.front()<<endl;
            answer[i]=vectAnswer.front();
            vectAnswer.erase(vectAnswer.begin());
        }
    }
    getline(cin,fullLine);
    while(!isValidInput(fullLine,1,5,1))
    {
        cout << "Invalid Input"<<endl;
        getline(cin,fullLine);
    }
    if (correct==answer[stoi(fullLine)-1]||fullLine=="5")
    {
        cout << "Correct"<<endl;
        cout << "You just discovered that this planet has " << planet.getTrait() << ". This discovery has been added to your log book." << endl;
        
    }
    else
    {
        cout << "Incorrect answer! Reduced your health by 1% because of frustration." << endl;
        player.setHealth(totalReduceHealth);
        dead(player,shuttle,game);
    }
}
void printFile(string filename)
{
    string line;
    ifstream fin;
    fin.open(filename);
    if (fin.fail())
    {
        cout << "couldn't open file" << endl;
    }
    while (!fin.eof())
    {
        getline(fin, line);
        cout << line << endl;
    }
    fin.close();
}
int reIndex(string arr[], int size)
{
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == "")
        {
            flag = true;
            continue;
        }
        if (flag)
        {
            arr[i - 1] = arr[i];
        }
    }
    return size - 1;
}
int readCrewmates(string filename, string nameArr[], string abilitiesArr[], int nameSize, int abilitiesSize, int iterator)
{
    string line;
    ifstream fin;
    string arr[2];
    fin.open(filename);
    if (fin.fail())
    {
        cout << "couldn't open file" << endl;
    }
    while (!fin.eof())
    {
        if (iterator == nameSize || iterator == abilitiesSize)
        {
            return -1;
        }
        getline(fin, line);
        split(line, ';', arr, 2);
        nameArr[iterator] = arr[0];
        abilitiesArr[iterator] = arr[1];
        arr[0] = "";
        arr[1] = "";
        iterator++;
    }
    fin.close();
    return iterator;
}
void resourceCenter(Shuttle &shuttle, Humans &player, Game &game)
{
    string input;
    int option1, option2;
    string weaponList[3] = {"Light Saber", "Blaster", "Beam gun"};
    int weaponPriceList[3] = {1000, 2000, 5000};
    vector<string> menu = {"Weapon", "Translator", "Space suit", "Medical kits", "Fuel", "Purchase and Leave"};
    char firstLetter;
    if (shuttle.getTranslator())
    {
        menu.erase(menu.begin() + 1);
    }
    while (true)
    {
        cout << "Which item do you wish to buy?" << endl;
        for (int i = 0; i < menu.size(); i++)
        {
            cout << i + 1 << ". " << menu[i] << endl;
        }
        getline(cin, input);
        if (!isValidInput(input, 1, 6, 1))
        {
            cout << "Re-enter a valid option." << endl;
            continue;
        }
        option1 = (int)input[0] - 48;
        firstLetter = menu[option1 - 1][0];
        switch (firstLetter)
        {
        case 'W':
            while (true)
            {
                cout << "Which weapon type do you wish to buy?" << endl;
                for (int i = 0; i < 3; i++)
                {
                    cout << i + 1 << "." << weaponList[i] << endl;
                }
                cout << "4. Go back to menu" << endl;
                getline(cin, input);
                if (!isValidInput(input, 1, 4, 1))
                {
                    cout << "Re-enter a valid option." << endl;
                    continue;
                }
                option2 = (int)input[0] - 48;
                if (option2 == 4)
                {
                    break;
                }
                cout << "How many " << weaponList[option2 - 1] << "s would you like ($" << weaponPriceList[option2 - 1] << " each)?" << endl;
                getline(cin, input);
                while (!isValidInput(input, 1, 2, 1))
                {
                    cout << "You cannot have more than two weapons at the same time, re-enter a valid quantity." << endl;
                    getline(cin, input);
                }
                option1 = (int)input[0] - 48;
                if (shuttle.getNumWeapons() + option1 > 2)
                {
                    cout << "You have too many weapons to buy that many " << weaponList[option2 - 1] << "s" << endl;
                    continue;
                }
                else
                {
                    if (shuttle.getMoney() - (weaponPriceList[option2 - 1] * option1) < 0)
                    {
                        cout << "lmao, you broke welcome to the club" << endl;
                        break;
                    }
                    for (int i = 0; i < option1; i++)
                    {
                        if (!shuttle.addWeapon(weaponList[option2 - 1]))
                        {
                            cout << "addWeapon broke" << endl;
                        }
                        else
                        {
                            shuttle.purchase(weaponPriceList[option2 - 1]);
                            shuttle.addWeapon(weaponList[option2 - 1]);
                        }
                    }
                    cout << "You have $" << shuttle.getMoney() << " left." << endl;
                    break;
                }
            }
            break;
        case 'T':
            if (shuttle.getTranslator())
            {
                cout << "you already have a translator" << endl;
                break;
            }
            cout << "Would you like to purchase a translator device ($5000)? 1 for yes, 0 for no." << endl;
            getline(cin, input);
            while (!isValidInput(input, 0, 1, 1))
            {
                cout << "Re-enter a valid option." << endl;
                getline(cin, input);
            }
            if (input == "1" && ((shuttle.getMoney() - 5000) > 0))
            {
                shuttle.setTranslator(true);
                shuttle.purchase(5000);
                menu.erase(menu.begin() + 1);
                cout << "You have $" << shuttle.getMoney() << " left." << endl;
            }
            else
            {
            }
            break;
        case 'S':
            if (shuttle.getSpaceSuit() == 5)
            {
                cout << "You already have the best Space Suit." << endl;
                break;
            }
            cout << "Would you like to upgrade your spacesuit to any of these? The space suit health will be set to 100%." << endl;
            for (int i = shuttle.getSpaceSuit(); i < 5; i++)
            {
                cout << i - shuttle.getSpaceSuit() + 1 << ". Space suit grade " << i + 1 << " is $" << (i + 1 - shuttle.getSpaceSuit()) * 5000 << endl;
            }
            getline(cin, input);
            while (!isValidInput(input, 1, 5 - shuttle.getSpaceSuit(), 1))
            {
                cout << "Re-enter a valid option." << endl;
                getline(cin, input);
            }
            option1 = (int)input[0] - 48;
            if (shuttle.getMoney() < 5000 * (option1))
            {
                cout << "You do not have enough money for that." << endl;
            }
            else
            {
                shuttle.setSpaceSuit(shuttle.getSpaceSuit() + option1);
                shuttle.purchase(option1 * 5000);
                cout << "You have $" << shuttle.getMoney() << " left." << endl;
            }
            break;
        case 'M':
            if (shuttle.getNumMeds() == 5)
            {
                cout << "You already have max number of med kits" << endl;
                break;
            }
            cout << "How many medical kits would you like to purchase ($2,000 each)? You currently have " << shuttle.getNumMeds() << ", and can at most have 5." << endl;
            getline(cin, input);
            while (!isValidInput(input, 1, 5 - shuttle.getNumMeds(), 1))
            {
                cout << "You can only hold 5 med kits. Re-enter a vaild option" << endl;
                getline(cin, input);
            }
            option1 = (int)input[0] - 48;
            if (shuttle.purchase(option1 * 2000))
            {
                shuttle.setNumMeds(option1 + shuttle.getNumMeds());
                cout << "You have $" << shuttle.getMoney() << " left." << endl;
            }
            break;
        case 'F':
            if (shuttle.getFuel() == 400000)
            {
                cout << "The fuel tank is already full" << endl;
                break;
            }
            cout << "You have " << shuttle.getFuel() << " gallons of fuel. Your spacecraft can hold 400k gallons of fuel." << endl;
            cout << "How many gallons would you like to purchase ($1,000 per 10,000 gallons)? Input must be in multiples of 10000s" << endl;
            while (true)
            {
                getline(cin, input);
                if (!isValidInput(input, 0, 400000 - shuttle.getFuel(), input.length()))
                {
                    cout << "Input must be in multiples of 10000s. Re-enter a valid quantity." << endl;
                    continue;
                }
                option1 = stoi(input);
                if (option1 % 10000 != 0)
                {
                    cout << "Input must be in multiples of 10000s. Re-enter a valid quantity." << endl;
                    continue;
                }
                if (shuttle.purchase(option1 / 10))
                {
                    shuttle.setFuel(shuttle.getFuel() + option1);
                    break;
                }
                else
                {
                    cout << "You can't afford gas, relatable" << endl;
                }
            }
            cout << "You have $" << shuttle.getMoney() << " left." << endl;
            break;
        case 'P':
            if (game.planetsExplored() == 0)
            {
                cout << "Great purchase, Elon is sending a Cybertruck with your supplies to you right now." << endl;
                return;
            }
            else
            {
                cout << "Great purchase, Elon is sending a Falcon rocket with your supplies to you right now." << endl;
                return;
            }
            break;

        default:
            cout << "Re-enter a valid option." << endl;
            continue;
            break;
        }
    }
}
void pickCrew(string nameArr[], string abilitiesArr[], string arrA[], int size, Humans &crew)
{
    string choice;
    int index;
    int digits = (size / 10) + 1;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ". " << nameArr[i] << endl;
        cout << "Ability: " << abilitiesArr[i] << endl;
        cout << endl;
    }
    getline(cin, choice);
    while (!isValidInput(choice, 1, size, digits))
    {
        cout << "Invalid input. Re-enter a valid input" << endl;
        getline(cin, choice);
    }
    index = stoi(choice);
    crew.setName(nameArr[index - 1]);
    crew.setAttributes(arrA[index - 1][0]);
    nameArr[index - 1] = "";
    arrA[index - 1] = "";
    abilitiesArr[index - 1] = "";
}

void genPlanet(string filename, Planets &planet)
{
    string name = "";
    double diameter;
    string line;
    int ascii;
    int counter = 0;
    srand(time(NULL));
    for (int i = 0; i < 6; i++)
    {
        ascii = rand() % 36;
        if (ascii < 10)
        {
            name += to_string(ascii);
        }
        else
        {
            name += char(ascii + 55);
        }
    }
    ifstream fin;
    fin.open(filename);
    ascii = rand() % 3125;
    while (!fin.eof())
    {
        getline(fin, line);
        if (counter == ascii)
        {
            break;
        }
        counter++;
    }
    name += "-" + line;
    planet.setName(name);
    diameter = (double)(rand() % 15 + 1) / 2.0;
    planet.setSize(diameter);
    planet.setCapacity((615 * diameter));
}

Planets travel(Shuttle &shuttle, int &fuelCost)
{
    Planets planet;
    genPlanet("four_letter_words.txt", planet);
    shuttle.setFuel(shuttle.getFuel() - fuelCost);
    fuelCost = (fuelCost * fuelCost) / 100000 + fuelCost;
    return planet;
}

int fightAlien(Humans &player, Shuttle &shuttle, Aliens &alien, Game &game)
{
    string fight;
    cout << "You just ran into an alien! Think you can beat this dangerous alien for helping save humanity? attack(y) or forfeit(n)" << endl;
    cin >> fight;
    while (fight != "y" && fight != "n" && fight != "Y" && fight != "N")
    {
        cout << "Re-enter a valid option." << endl;
        cin >> fight;
    }
    if (fight == "n" || fight == "N")
    {
        if (shuttle.getNumWeapons() >= 2)
        {
            
            shuttle.breakWeapon(shuttle.getWeaponAt(0));
            return 0;
        }
        else if (shuttle.getNumWeapons() < 2)
        {
            if (shuttle.getMoney() < 10000)
            {
                shuttle.setMoney(0);
            }
            else if (shuttle.getMoney() >= 1000)
            {
                shuttle.setMoney(shuttle.getMoney() - 10000);
            }
            return -1;
        }
    }
    else if (fight == "y" || fight == "Y")
    {
        if (shuttle.getNumWeapons() < 2)
        {
            if (shuttle.getMoney() < 1000)
            {
                return -2;
            }
            else if (shuttle.getMoney() >= 1000)
            {
                cout << "You have less than two weapons to fight with! Lets visit the resource center and buy a weapon!" << endl;
                resourceCenter(shuttle, player, game);
                fightAlien(player, shuttle, alien, game);
                if (game.getCrewAblilty(1)=='a'||game.getCrewAblilty(2)=='a')
                {
                    player.setHealth(player.getHealth()+5);
                }
            }
        }
        else if (shuttle.getNumWeapons() == 2)
        {
            // rest of battle
            int opt;
            cout << "Let's attack! Choose a weapon from your arsenal quickly and attack before the enemy advances!" << endl;
            cout << "1. " << shuttle.getWeaponAt(0) << endl;
            cout << "2. " << shuttle.getWeaponAt(1) << endl;
            cin >> opt;
            int weaponType = 0;
            if (shuttle.getWeaponAt(opt) == "Light Saber")
            {
                weaponType = 1;
                shuttle.setWeaponAt(1, "Light Saber");
            }
            else if (shuttle.getWeaponAt(opt) == "Blasters")
            {
                weaponType = 2;
                shuttle.setWeaponAt(1, "Blasters");
            }
            else if (shuttle.getWeaponAt(opt) == "Beam gun")
            {
                weaponType = 3;
                shuttle.setWeaponAt(1, "Beam gun");
            }
            int fighterPresent = rand() % 2 + 0;
            int planetNumber = rand() % 5 + 1;
            int r1 = rand() % 6 + 1;
            int r2 = rand() % 6 + 1;
            int result = (r1 * weaponType) * (1 + fighterPresent) - (r2 * planetNumber);
            if (result > 0)
            {
                return 1;
            }
            else
            {
                return -3;
            }
        }
    }
    return -4;
}

void mapRun(Humans &player, Shuttle &shuttle, Map &map1, Aliens &alien, Game &game, Planets &planet)
{
    double weatherHealth = player.getHealth() * 0.10;
    double totalWeatherHealth = player.getHealth() - weatherHealth;
    double weatherSpace = shuttle.getSpaceSuitHealth() * (50 - 10 * shuttle.getSpaceSuit()) / 100;
    double totalWeatherSpace = shuttle.getSpaceSuitHealth() - weatherSpace;

    double craterHealth = player.getHealth() * 0.50;
    double totalCraterHealth = player.getHealth() - craterHealth;
    double craterSpace = shuttle.getSpaceSuitHealth() * (50 - 10 * shuttle.getSpaceSuit()) / 100;
    double totalCraterSpace = shuttle.getSpaceSuitHealth() - craterSpace;

    double sicknessHealth = player.getHealth() * 0.30;
    double totalSicknessHealth = player.getHealth() - sicknessHealth;

    double fightHealth = player.getHealth() * 0.30;
    double totalFightHealth = player.getHealth() - fightHealth;
    double fightSpace = shuttle.getSpaceSuitHealth() * (100 - 20 * shuttle.getSpaceSuit()) / 100;
    double totalFightSpace = shuttle.getSpaceSuitHealth() - fightSpace;

    double winHealth = shuttle.getSpaceSuitHealth() * 0.10;
    double totalWinHealth = shuttle.getSpaceSuitHealth() - winHealth;

    int percentTruth=70;
    int bonus=50;
    if (game.getCrewAblilty(1)=='e'||game.getCrewAblilty(2)=='e')
    {
        bonus = 150;
    }
    if(game.getCrewAblilty(1)=='d'||game.getCrewAblilty(2)=='d')
    {
        percentTruth=80;
    }
    char choice;
    cout <<"Planet: " << planet.getName()<<endl;
    map1.displayMap();
    char option;
    string line;
    cout << "Select one: w. up s. down d. right a. left m. menu" << endl;
    getline(cin, line);
    option=line[0];
    while (option != 'w' && option != 's' && option != 'd' && option != 'a' && option != 'm')
    {
        cout << "Re-enter a valid option." << endl;
        getline(cin, line);
        option=line[0];
    }
    while (option != 'm')
    {
        shuttle.setMoney(shuttle.getMoney()+bonus);
        map1.getPlayerColPosition();
        map1.getPlayerRowPosition();
        map1.executeMove(option);
        map1.displayMap();
        cout << "Select one: w. up s. down d. right a. left m. menu" << endl;
        getline(cin, line);
        option=line[0];
        if (map1.isMisfortuneLocaton() == true)
        {
            if (map1.getMisfortuneType() == 1)
            {
                readAliens(alien);
                int value = fightAlien(player, shuttle, alien, game);
                if (game.getCrewAblilty(1)=='a'||game.getCrewAblilty(2)=='a')
                {
                    player.setHealth(player.getHealth()+5);
                }
                if (value == -3)
                {
                    shuttle.setSpaceSuitHealth(totalFightSpace);
                    player.setHealth(totalFightHealth);
                    readAliens(alien);
                    cout << "Aggh! You lost the battle! The alien seems to be hard for you! Tough times. Unfortunately, you experience the following due to this loss:" << endl;
                    cout << "1. Your health was decreased by 30%." << endl;
                    cout << "2. Your suit health decreased by " << fightSpace << "%." << endl;
                    dead(player,shuttle,game);
                }
                else if (value == -2)
                {
                    cout << "You only have one weapon nor enough money to buy another weapon. Consequently, the alien attacked and defeated you could not retreat :(" << endl;
                }
                else if (value == -1)
                {
                    cout << "Really?! You chose to forfeit the battle? This is disappointing! Since you do not have a weapon, you just lost a huge chunk of money from your account. Hopefully, you git gud before you encounter the next alien." << endl;
                }
                else if (value == 0)
                {
                    cout << "Really?! You chose to forfeit the battle? This is disappointing! You lost a weapon due to this decision. Hopefully, you git gud before you encounter the next alien." << endl;
                }
                else if (value == 1)
                {
                    shuttle.setSpaceSuitHealth(totalWinHealth);
                    if (shuttle.getNumWeapons() < 2)
                    {
                        shuttle.addWeapon("Blaster");
                        cout << "You defeated the alien! Great Job! You won a weapon. But you lost 10% of space suit health while fighting." << endl;
                    }
                    else
                    {
                        cout << "You defeated the alien! Great Job! You saw the enemy's weapon lying down but you cannot carry with you as you already have 2 weapons. Unfortunately, you lost 10% of space suit health while fighting." << endl;
                    }
                }
            }
            else if (map1.getMisfortuneType() == 2)
            { // extreme weather event
                cout << "Oh no! There was an extreme weather event. Your health decreased by 10%." << endl;
                shuttle.setSpaceSuitHealth(totalWeatherSpace);
                player.setHealth(totalWeatherHealth);
                dead(player,shuttle,game);
            }
            else if (map1.getMisfortuneType() == 3)
            { // fall into crater
                cout << "Oh no! You fell into a crater. Your health decreased by 50%." << endl;
                shuttle.setSpaceSuitHealth(totalCraterSpace);
                player.setHealth(totalCraterHealth);
                dead(player,shuttle,game);
            }
            else if (map1.getMisfortuneType() == 4)
            { // space sickness
                cout << "Oh no! You have space sickness. Your health decreased by 30%." << endl;
                player.setHealth(totalSicknessHealth);
                dead(player,shuttle,game);
            }
        }
        else if (map1.isNPCLocation() == true)
        {
            cout << "You have run into a friendly alien!" << endl;
            if (shuttle.getTranslator() == false)
            {
                cout << "You do not have a translator and cannot communicate with this alien. This alien may have useful information for you or money to offer, you can purchase a translator from the store if you would like to talk to them." << endl;
            }
            else if (shuttle.getTranslator() == true)
            {
                cout << "You can communicate with this alien. You can defeat them in rock, paper, scissors three times and gain $200 (c) or you can ask them about the habitability of this planet (a). The chance of the alien telling the truth is "<<percentTruth<<"%. You can only pick one option." << endl;
                getline(cin, line);
                choice=line[0];
                while (choice != 'c' && choice != 'a')
                {
                    cout << "Re-enter a valid option." << endl;
                    getline(cin, line);
                    choice=line[0];
                }
                if (choice == 'c')
                {
                    rpsGame(shuttle);
                }
                else if (choice == 'a')
                {
                    int two = rand() % (2 - 1 + 1) + 1;
                    char response1;
                    char response2;
                    if (two == 1)
                    {
                        cout << "Hello human! I have looked around this planet and think this would make a great home for you." << endl;
                        cout << "How would you like to respond?" << endl;
                        cout << "1. That's great to hear! I will take your word on that.\n2. I don't know if I should believe you...\n";
                        getline(cin, line);
                        response1=line[0];
                        while (response1 != '1' && response1 != '2')
                        {
                            cout << "Re-enter a valid input." << endl;
                            getline(cin, line);
                            response1=line[0];
                        }
                        if (response1 == '1')
                        {
                            cout << "That's great to hear! I will take your word on that." << endl;
                        }
                        else if (response1 == '2')
                        {
                            cout << "I don't know if I should believe you..." << endl;
                        }
                    }
                    else if (two == 2)
                    {
                        cout << "Hello human! I have looked around this planet and think this would be a terrible choice for a home. Your fragile species could not handle these conditions, I would suggest finding someplace else." << endl;
                        cout << "How would you like to respond?" << endl;
                        cout << "1. Wow that's disappointing. This planet looked so promising too.\n2. You are totally lying, you just don't want humans to come here.\n";
                        getline(cin, line);
                        response2=line[0];
                        while (response2 != '1' && response2 != '2')
                        {
                            cout << "Re-enter a valid input." << endl;
                            getline(cin, line);
                            response2=line[0];
                        }
                        if (response2 == '1')
                        {
                            cout << "Wow that's disappointing. This planet looked so promising too." << endl;
                        }
                        else if (response2 == '2')
                        {
                            cout << "You are totally lying, you just don't want humans to come here." << endl;
                        }
                    }
                }
            }
        }
        else if (map1.isSiteLocation() == true)
        {
            trivia(player, planet, shuttle, game);
            game.setCurrentPlanet(planet);
        }
    }
    return;
}

int main()
{
    string input, playerName, crewNameArr[10], crewAbilitiesArr[10];
    string arrA[10];
    string name;
    int place, fuelCost, option1;
    Shuttle shuttle;
    Humans player;
    Aliens alien;
    Game game;
    Map map1 = randomMap();
    Planets planet, currentPlanet;
    Humans crew1;
    Humans crew2;
    cout << "Please enter your name: " << endl;
    getline(cin, playerName);
    player.setName(playerName);
    
    cout << "Welcome, " << player.getName() << "!" << endl;
    //------------------------------------------------------------
    place = readCrewmates("crewmates.txt", crewNameArr, crewAbilitiesArr, 10, 10, 0);
    place = readCrewmates("crewmates_ec.txt", crewNameArr, crewAbilitiesArr, 10, 10, place);
    for (int i = 0; i < 10; i++)
    {
        arrA[i] = char(i + 97);
    }
    pickCrew(crewNameArr, crewAbilitiesArr, arrA, 10, crew1);
    place = reIndex(crewNameArr, 10);
    reIndex(crewAbilitiesArr, 10);
    reIndex(arrA, 10);
    cout << "Select your second crewmate" << endl;
    pickCrew(crewNameArr, crewAbilitiesArr, arrA, place, crew2);
    cout << crew1.getName() << crew1.getAttributes() << endl;
    cout << crew2.getName() << crew2.getAttributes() << endl;
    game.setCrew(player, crew1, crew2);
    //------------------------------------------------------------
    if (crew1.getAttributes() == 'c' || crew2.getAttributes() == 'c')
    {
        shuttle.setFuel(400000);
    }
    if (crew1.getAttributes() == 'h' || crew2.getAttributes() == 'h')
    {
        shuttle.setSpaceSuit(3);
    }
    printFile("resource_center_info.txt");
    resourceCenter(shuttle, player, game);
    cout << "Hit enter when you are ready to enter space and go to your first planet.";
    getline(cin, input);
    cout << endl;
    while (input.length() > 0)
    {
        cout << "Just hit enter" << endl;
        getline(cin, input);
    }
    //<--------------------------------------------------------PHASE 1------------------------------------------------------------------>
    cout << "Lift off!" << endl;
    cout << endl;
    fuelCost = 50000;
    planet = travel(shuttle, fuelCost);
    game.addPlanet(planet);
    while (true)
    {
        cout << "Select one:" << endl;
        cout << "1. Move" << endl;
        cout << "2. View status" << endl;
        cout << "3. View log book" << endl;
        cout << "4. Resource center" << endl;
        cout << "5. Report planet as habitable" << endl;
        cout << "6. Enter wormhole to next planet" << endl;
        cout << "7. Give up" << endl;
        getline(cin, input);
        //trivia(player, planet, shuttle, game);
        //game.setCurrentPlanet(planet);
        while (!isValidInput(input, 1, 7, 1))
        {
            cout << "Invalid input Main menu" << endl;
            getline(cin, input);
        }
        option1 = (int)input[0] - 48;
        switch (option1)
        {
        case 1:
            mapRun(player, shuttle, map1, alien, game, planet);
            break;
        case 2:
            game.viewStatus(shuttle, player);
            break;
        case 3:
            game.setCrew(player, crew1, crew2);
            game.displayLogCurrent();
            break;
        case 4:
            resourceCenter(shuttle, player, game);
            break;
        case 5:
            currentPlanet = game.getCurrentPlanet();
            if (currentPlanet.getPlayerReport() == -1)
            {
                // cout << currentPlanet.getPlayerReport() << endl;
                cout << "Are you sure you want to report back to mission control that this planet is habitable? As a reminder, here is your log book:" << endl;
                game.setCrew(player, crew1, crew2);
                game.displayLogCurrent();
                cout << endl
                     << "Reporting this planet is irreversible." << endl;
                cout << "If the planet is in fact habitable, you will save " << currentPlanet.getCapacity() << " million people! If it’s not, the people sent to this planet will die." << endl;
                cout << endl
                     << "Ready to report?[1 for yes, 0 for no]" << endl;
                getline(cin, input);
                while (!isValidInput(input, 0, 1, 1))
                {
                    cout << "Invalid input" << endl;
                    getline(cin, input);
                }
                if (input[0] == '1')
                {
                    cout << "How would you like to report the planet?[1 for Habitable,0 for Non-Habiatble]" << endl;
                    name = currentPlanet.getName();
                    getline(cin, input);
                    while (!isValidInput(input, 0, 1, 1))
                    {
                        cout << "Invalid input" << endl;
                        getline(cin, input);
                    }
                    // cout << stoi(input) << endl;
                    currentPlanet.setPlayerReport(stoi(input));
                    // cout << currentPlanet.getPlayerReport() << endl;
                    cout << "For planet:" << currentPlanet.getName() << endl;
                    if (currentPlanet.isHabitable() && ((int)input[0] - 48 == 1))
                    {
                        if ((currentPlanet.getCapacity() + game.getHumansSaved() + game.getHumansPerished()) > 8000)
                        {
                            place = 8000 - (game.getHumansSaved() + game.getHumansPerished());
                            game.moreSaved(8000 - (game.getHumansSaved() + game.getHumansPerished()));
                            // game.addCorrectReports();
                        }
                        else
                        {
                            game.moreSaved(currentPlanet.getCapacity());
                            place = currentPlanet.getCapacity();
                        }
                        cout << "Congratulations! You have saved " << place << " million people!\n";
                        cout << "This planet is their new home. You have " << 8000 - (game.getHumansSaved() + game.getHumansPerished()) << " million people to save left.\n";
                        game.addCorrectReports();
                    }
                    else if (currentPlanet.isHabitable() && !((int)input[0] - 48 == 1))
                    {
                        cout << "That planet was habitable, what a waste\n";
                        game.addIncorrectReports();
                    }
                    else if (!(currentPlanet.isHabitable()) && ((int)input[0] - 48 == 1))
                    {
                        if ((currentPlanet.getCapacity() + game.getHumansSaved() + game.getHumansPerished()) > 8000)
                        {
                            place = 8000 - (game.getHumansSaved() + game.getHumansPerished());
                            game.morePerished(8000 - (game.getHumansSaved() + game.getHumansPerished()));
                            // game.addIncorrectReports();
                        }
                        else
                        {
                            game.morePerished(currentPlanet.getCapacity());
                            place = currentPlanet.getCapacity();
                        }
                        cout << "Your choice has led to tragedy. " << place << " million people were sent to this planet and died due to its in-hospitable conditions." << endl;
                        cout << "You still have " << 8000 - (game.getHumansSaved() + game.getHumansPerished()) << " million people left to save, so keep exploring.\n";
                        game.addIncorrectReports();
                    }
                    else
                    {
                        cout << "Good call That planet was in-hospitable" << endl;
                        game.addCorrectReports();
                    }
                    // cout << game.getCurrentPlanet().getName() <<endl;4
                    game.setCurrentPlanet(currentPlanet);
                    if ((game.getHumansPerished() + game.getHumansSaved()) == 8000)
                    {
                        gameOver(3, game);
                    }
                }
                else
                {
                    break;
                }
            }
            else
            {
                cout << "You have already reported on this planet" << endl;
            }
            break;
        case 6:
            cout << "Are you sure you would like to enter this wormhole?" << endl;
            cout << "You will start a new page in your log book and you will lose fuel." << endl;
            cout << "Enter wormhole [1 for yes, 0 for n]" << endl;
            getline(cin, input);
            while (!isValidInput(input, 0, 1, 1))
            {
                cout << "Invalid Input. Re-enter valid input" << endl;
                getline(cin, input);
            }
            if (input[0] == '1')
            {
                planet = travel(shuttle, fuelCost);
                map1 = randomMap();
                game.addPlanet(planet);
                break;
            }
            else
            {
                break;
            }
        case 7:
            gameOver(2, game);
            break;
        }
    }
}