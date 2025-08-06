#include "GameCharacter.h"

GameCharacter::GameCharacter(string n, string desc, int h, int a, int d, Item drop)
{
    name = n;
    description = desc;
    maxHealth = h;
    currentHealth = h;
    attack = a;
    defence = d;
    dropItem = drop;
}

int GameCharacter::takeDamage(int amount)
{
    int damage = amount - defence;
    if (damage < 0)
    {
        damage = 0;
    }
    currentHealth -= damage;
    return damage;
}

bool GameCharacter::checkIsDead()
{
    return currentHealth <= 0;
}