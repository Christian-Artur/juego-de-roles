#ifndef RPG_ENEMY_H
#define RPG_ENEMY_H

#include "../Character/Character.h"

class Enemy: public Character {
public:
    Enemy(string, int, int, int, int);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    void smartAttack(Character* player, Character* otherPlayer);
    bool tryEscape(int playerHealth);
    void specialAbility(Character* player);
};

#endif // RPG_ENEMY_H
