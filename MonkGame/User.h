#pragma once
#include <string>
using namespace std;
class user
{
public:
    user(std::string, std::string,std:: string, int, int);
    void setName(std::string);
    void setDescription(std::string);
    void setRoom(std::string);
    void setLevel(int);
    void setHealth(double);
    void setMaxHealth();
    void setDamage();
    std::string getName();
    std::string getRoom();
    std::string getDescription();
    int getLevel();
    double getHealth();
    double getMaxHealth();
    int getDamage();

private:
    std::string playerName;
    std::string playerRoom;
    std::string playerDescription;
    int playerLevel;
    double playerHealth;
    double playerMaxHealth;
    int playerDamage;
};

