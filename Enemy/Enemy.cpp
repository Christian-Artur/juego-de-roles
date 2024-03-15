#include "Enemy.h"
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

using namespace std;

Enemy::Enemy(string name, int health, int attack, int defense, int speed) : Character(name, health, attack, defense, speed) {
    srand(time(0)); // Initialize random seed
}

void Enemy::doAttack(Character *target) {
    int trueDamage = getAttack() - target->getDefense();
    target->takeDamage(trueDamage);
}

void Enemy::takeDamage(int damage) {
    setHealth(getHealth() - damage);
    if(getHealth() <= 0) {
        cout<<getName()<<" has died"<<endl;
    }
    else {
        cout<<getName()<<" has taken " << damage << " damage" << endl;
    }
}

void Enemy::smartAttack(Character* player, Character* otherPlayer) {
    // Implementing attack logic: target the player with lower health
    if (player->getHealth() <= otherPlayer->getHealth()) {
        doAttack(player);
    } else {
        doAttack(otherPlayer);
    }
}

bool Enemy::tryEscape(int playerHealth) {
    // Implementing escape logic: if enemy's health is below 15%, attempt to escape with a 5% chance
    if ((static_cast<double>(getHealth()) / getHealth()) < 0.15) {
        int escapeChance = rand() % 100 + 1; // Random number between 1 and 100
        return escapeChance <= 5; // 5% chance of escaping
    }
    return false;
}

void Enemy::specialAbility(Character* player) {
    // Implementing special ability: Example
    cout << "Merodeador " << getName() << " Uso la habilidad especial!" << endl;
    // Your implementation goes here
}
