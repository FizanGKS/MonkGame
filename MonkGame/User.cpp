#include <string>
#include "User.h"
user::user(std::string name, std::string description, std::string room, int level = 1, int EXP = 0)
{
    setName(name);
    setRoom(room);
    setDescription(description);
    setLevel(level);
    setMaxHealth();
    setHealth(playerMaxHealth);
    setDamage();
}

void user::setName(std::string name)
{
    playerName = name;
}
void user::setRoom(std::string room)
{
    playerRoom = room;
}
void user::setDescription(std::string description)
{
    playerDescription = description;
}

void user::setLevel(int level)
{
    playerLevel = level;
}
void user::setHealth(double health)
{
    playerHealth = health;
}
void user::setMaxHealth()
{
    playerMaxHealth = (15 * getLevel());
}
void user::setDamage()
{
    playerDamage = (3 * getLevel());
}

std::string user::getName()
{
    return playerName;
}

std::string user::getRoom()
{
    return playerRoom;
}

std::string user::getDescription()
{
    return playerDescription;
}
int user::getLevel()
{
    return playerLevel;
}
double user::getHealth()
{
    return playerHealth;
}
double user::getMaxHealth()
{
    return playerMaxHealth;
}
int user::getDamage()
{
    return playerDamage;
}
