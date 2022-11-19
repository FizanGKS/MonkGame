
#include <string>
#include "MonsterC.h"
MonsterC::MonsterC(std::string name, int lvl, std::string room, int difficulty)
{
    setName(name);
    setLevel(lvl);
    setRoom(room);
    setDifficulty(difficulty);
    setDamage();
    setMaxHealth();
    setHealth(monsterMaxHealth);

}

void MonsterC::setName(std::string name)
{
    monsterName = name;
}

void MonsterC::setLevel(int level)
{
    monsterLevel = level;
}

void MonsterC::setRoom(std::string room)
{
    monsterRoom = room;
}

void MonsterC::setDifficulty(int difficulty)
{
    monsterDifficulty = difficulty;
}

void MonsterC::setDamage()
{
    //monsterDamage = (2 * (getLevel()) + ((getDifficulty() * getLevel()) / 2));            this changes the damage depending on the random difficulty
    monsterDamage = (2);
}

void MonsterC::setHealth(double health)
{
    monsterHealth = health;
}
void MonsterC::setMaxHealth()
{
    monsterMaxHealth = (10 * (getDifficulty() + getLevel()));
}
std::string MonsterC::getName()
{
    return monsterName;
}

int MonsterC::getLevel()
{
    return monsterLevel;
}
std::string MonsterC::getRoom()
{
    return monsterRoom;
}
int MonsterC::getDifficulty()
{
    return monsterDifficulty;
}
int MonsterC::getDamage()
{
    return monsterDamage;
}
double MonsterC::getHealth()
{
    return monsterHealth;
}
double MonsterC::getMaxHealth()
{
    return monsterMaxHealth;
} 

