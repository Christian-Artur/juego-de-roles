#include "Player.h"
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

using namespace std;

Player::Player(string name, int health, int attack, int defense, int speed) : Character(name, health, attack, defense, speed) {
    experience = 0;
    level = 1;
    srand(time(0)); // Initialize random seed
}

void Player::doAttack(Character *target) {
    int trueDamage = getAttack() - target->getDefense();
    target->takeDamage(trueDamage);
}

void Player::takeDamage(int damage) {
    setHealth(getHealth() - damage);

    if(getHealth() <= 0) {
        cout<<"Has muerto"<<endl;
    }
    else {
        cout<<"Has recibido" << damage << " daño" << endl;
    }
}

void Player::flee(Character* enemy) {
    // Implementing flee logic: check if player's speed is higher than enemy's, and if so, flee
    int fleeChance = rand() % 100 + 1; // Random number between 1 and 100
    if (getSpeed() > enemy->getSpeed() && fleeChance <= 50) { // 50% chance of successful escape
        cout << "El Slayer ha escapado!" << endl;
    } else {
        cout << "El slayer no escapó!" << endl;
    }
}

void Player::emote() {
    cout<<"Se burla de ti" << endl;
}

void Player::levelUp() {
    level++;
    setHealth(getHealth() + 10);
    setAttack(getAttack() + 5);
    setDefense(getDefense() + 5);
    setSpeed(getSpeed() + 5); // <-- Aquí faltó cerrar el paréntesis
}
