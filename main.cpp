#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"

int main() {

    Player *player = new Player("Slayer", 100, 10, 5, 5);
    Enemy *enemy = new Enemy("Merodeador", 50, 5, 2, 3);

    while (player->getHealth() > 0 && enemy->getHealth() > 0) {
        // Turno del jugador
        player->doAttack(enemy);
        if (enemy->getHealth() <= 0) {
            cout << "Merodeador asesinado!" << endl;
            break;
        }

        // Turno del enemigo
        enemy->doAttack(player);
        if (player->getHealth() <= 0) {
            cout << "El Slayer ah muerto!" << endl;
            break;
        }
    }

    cout << "Estado final del Slayer:" << endl;
    cout << player->toString() << endl;
    cout << "Estado final del Merodeador:" << endl;
    cout << enemy->toString() << endl;

    delete player;
    delete enemy;
    return 0;
}
