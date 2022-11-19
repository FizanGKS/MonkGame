// MonkGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MonkGame.h"
#include "MonsterC.h"
#include "User.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <Windows.h>

using namespace std;

user fight(user account);
user ERoom(user account);
void death();
void TreasureRoom();

//reads the text file/ show ASCII Art
void printArt(string fileName) {
    ifstream file("Monk.txt");
    if (file.is_open()) {
        cout << file.rdbuf();
        file.close();
    }
    else {
        cout << "Error - File can't be opened";
    }
}

//Main containing the stratup screen/menu
int main()
{

    //variables
    string selection;

    string fileName = "Monk.txt";
    printArt(fileName);

    //print/ wait user input
    cout << "******MAIN MENU******" << endl;
    cout << "\n [1] Start the Game   [2] Quit Game\n" << endl;

    cout << endl << "Select an Option: ";
    cin >> selection;

    if (selection == "1") {
        l();
    }
    if (selection == "2") {
        exit(1);
    }

    }


//Fight function
user fight(user account)
{
    string option;
    string location[4] = { "Room n*1 ","Room n*2 ","Room n*3 ","Room n*4 " };
    string monsters[5][3] = { {"A Goblin","John Cena","A Vampire"} };
    Sleep(20);
    srand(time(NULL));
    int ranM = (rand() % 3); //random monster
    int ranD = (rand() % 3); //random difficulty
    MonsterC monster(monsters[account.getLevel() - 1][ranM], account.getLevel(), account.getRoom(), ranD);
    cout << "Right in front of you is:  " << monster.getName() << ", You " << monster.getRoom() << ", Be ready for the Fight" << "\n";
    Sleep(2000);
    do
    {
        system("cls");
        system("color 0C");

        //ASCII ART for fight room
        ifstream f("Fight.txt");
        if (f.is_open())
            cout << f.rdbuf();


        cout << "\n\n\n ###########IN A FIGHT###########\nHP:" << account.getHealth() << "                                         " << monster.getName() << " HP:" << monster.getHealth() << " difficulty:" << monster.getDifficulty() << "\n";
        cout << "Write A for attack or D for defence" << "\n";
        cin >> option;
        srand(time(NULL));
        if (option == "D" || option == "d")
        {
            if ((rand() % 2) == 1) {
                cout << "Defence sucessfull" << "\n";
                account.setHealth(account.getHealth() + 1);
           
            }
            else {
                cout << "Defence failed, the monster gets a free attack and you lose 1 health point\n";
                account.setHealth(account.getHealth() - 1);
                option = "A";
            }
        }
        if (option == "A" || option == "a")
        {
            //int attack = rand() % (account.getDamage());          ///To make the player attack with random damage
            //srand(time(NULL));
            int attack = (account.getDamage());
            //int monsterAttack = rand() % (monster.getDamage());  ///To make the monster attack with random damage
            monster.setHealth(monster.getHealth() - attack);
            account.setHealth(account.getHealth() - monster.getDamage());
            cout << "You attack the monster for:  " << attack << " damage\n";
            Sleep(500);
            cout << "Monster's Turn, Attacks For: " << monster.getDamage() << " damage\n";
            Sleep(500);
        }
    } while (monster.getHealth() > 0 && account.getHealth() > 0);
    cout << "\n\n\n ######################\nHP:"<< account.getHealth() << "         " << monster.getName() << "HP:" << monster.getHealth() << " difficulty:" << monster.getDifficulty() << "\n";
    

    //Treasure room when the monster is killed
    if (monster.getHealth() <= 0)
    {
        system("cls");
        TreasureRoom();
        exit(0);
    }

    //death screen when played is killed
    if (account.getHealth() <= 0)
    {
        death();
        exit(0);
    }
   
}

//Death Function
void death()
{   
    //Open the txt File
    ifstream f("GOver.txt");
    if (f.is_open())
        cout << f.rdbuf();
}

//Empty Room/ Pray room 
user ERoom(user account)
{   
    system("cls");
    //variable 
    string selection;

    //ASCII ART
    system("color 0A");


    //Open the txt File
    ifstream f("ERoom.txt");
    if (f.is_open())
        cout << f.rdbuf();

    cout << "\n [1] Pray     [2] Next Room\n" << endl;
    cout << endl << "Select an Option: ";
    cin >> selection;

    if (selection == "1") {
        account.setMaxHealth();
        account.setHealth(account.getMaxHealth()+ 1);
        cout << "\n You have gained +1 HP\n " << endl;
        return account;
    }

    if (selection == "2") {
        fight(account);
    }
}


//Function linked to the "Start Game" Button 
int l()
{
    string name;
    string description;
    int option1;
    cout << "Welcome, Please Enter Your Name: \n";
    cin >> name;
    cout << "Describe Yourself: \n";
    cin >> description;
    string location[4] = { "in the first Dungeon room","in the second Dungeon room","in the third Dungeon room" };
    user account(name, description, location[0], 1, 0);
    cout << "\nWelcome " << account.getName() << " described as " << account.getDescription() << "\n";
    while (1)
    {
        Sleep(500);
        cout << "Type 1 to walk forward or 2 to walk left or 3 to walk right\n";
        cin >> option1;
        if (option1 >= 1 && option1 <= 3)
        {
            Sleep(50 * (option1));
            srand(time(NULL));
            if (rand() % 3 == option1 - 1) {
                account = fight(account);
            }
            else
                account = ERoom(account);

        }
        else {
            cout << "\n##ERROR## Please enter a number between 1 and 3\n\n";
            cin.clear();
            cin.ignore();
        }
    }
    return 0;
}


//Treasure Room Function
void TreasureRoom()
{
    system("color 0B");
    //Open the txt File
    ifstream f("TRoom.txt");
    if (f.is_open())
        cout << f.rdbuf();
}
