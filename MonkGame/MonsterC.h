#pragma once
#include <string>

class MonsterC
{
public:
    MonsterC(std::string, int, std::string, int); // name,lvl,area,difficulty
    void setName(std::string);
    void setLevel(int);
    void setRoom(std::string);
    void setDamage();
    void setHealth(double);
    void setMaxHealth();
    void setDifficulty(int);
    std::string getName();
    int getLevel();
    std::string getRoom();
    int getDamage();
    double getHealth();
    double getMaxHealth();
    int getDifficulty();
  
private:
    std::string monsterName;
    std::string monsterRoom;
    int monsterLevel;
    int monsterDamage;
    double monsterHealth;
    double monsterMaxHealth;
    int monsterDifficulty;
};

