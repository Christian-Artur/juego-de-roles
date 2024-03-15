#include "Character.h"
#include <iostream>
Character::Character(string _name, int _health, int _attack, int _defense, int _speed) {
    name = _name;
    health = _health;
    attack = _attack;
    defense = _defense;
    speed = _speed;
}

void Character::setName(string _name) {
    name = _name;
}

string Character::getName() {
    return name;
}

void Character::setHealth(int _health) {
    health = _health;
}

int Character::getHealth() {
    return health;
}

void Character::setAttack(int _attack) {
    attack = _attack;
}

int Character::getAttack() {
    return attack;
}

void Character::setDefense(int _defense) {
    defense = _defense;
}

int Character::getDefense() {
    return defense;
}

void Character::setSpeed(int _speed) {
    speed = _speed;
}

int Character::getSpeed() {
    return speed;
}

string Character::toString() {
    return "Nombre: " + name + "\nVida: " + to_string(health) + "\nataque: " + to_string(attack) + "\nDefensa: " + to_string(defense) + "\nRapidez: " + to_string(speed);
}

void Character::doAttack(Character *target) {
    int trueDamage = getAttack() - target->getDefense();
    target->takeDamage(trueDamage);
}

void Character::takeDamage(int damage) {
    setHealth(getHealth() - damage);
    if(getHealth() <= 0) {
        cout<<getName()<<" Ha muerto"<<endl;
    }
    else {
        cout<<getName()<<" Ha recibido " << damage << " daño" << endl;
    }
}
