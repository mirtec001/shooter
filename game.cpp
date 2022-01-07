#include <SFML/Graphics.hpp>
#include <list>
#include <stdlib.h>
#include <time.h>
#include "player.hpp"
#include "enemy.hpp"
#include "bullet.hpp"


using namespace sf;

int main() {
    
    RenderWindow window((VideoMode(800, 600)), "Shooter take 2");
    Player player(Vector2f(500, 500));
    Clock deltaClock;
    std::list<Bullet> bulletList;
    std::list<Enemy> enemyList;
    int numEnemies = 1;

    srand(time(NULL));
    for(int i = 0; i < numEnemies; i++) {
        // Spawn our enemies outside of the screen
        float x = rand() % 800;
        float y = rand() % -1000 - 32;
        float speed = rand() % 2;
        enemyList.push_back(Enemy(Vector2f(x, y), speed));
    }

    while(window.isOpen()) {
        Time dt = deltaClock.restart();
        int moveSpeed = 300;
        Event event;
        while(window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::W)) {
                player.move(Vector2f(0, -moveSpeed));
            } else if (Keyboard::isKeyPressed(Keyboard::S)) {
                player.move(Vector2f(0, moveSpeed));
            } else if (Keyboard::isKeyPressed(Keyboard::A)) {
                player.move(Vector2f(-moveSpeed, 0));
            } else if (Keyboard::isKeyPressed(Keyboard::D)) {
                player.move(Vector2f(moveSpeed, 0));
            } else {
                player.move(Vector2f(0, 0));
            }

            if (Keyboard::isKeyPressed(Keyboard::J)) {
                bulletList.push_back(Bullet(player.getPosition(), "left"));
            } else if (Keyboard::isKeyPressed(Keyboard::L)) {
                bulletList.push_back(Bullet(player.getPosition(), "right"));
            } else if (Keyboard::isKeyPressed(Keyboard::I)) {
                bulletList.push_back(Bullet(player.getPosition(), "up"));
            } else if (Keyboard::isKeyPressed(Keyboard::K)) {
                bulletList.push_back(Bullet(player.getPosition(), "down"));
            }

        }
        std::list<Bullet>::iterator it;
        std::list<Enemy>::iterator enemyIt;

        for (it = bulletList.begin(); it != bulletList.end(); it++) {
            if (it->getDirection() == "left") {
                it->update(Vector2f(-moveSpeed * 2, 0), dt);
            } else if (it->getDirection() == "right") {
                it->update(Vector2f(moveSpeed * 2, 0), dt);
            } else if (it->getDirection() == "up") {
                it->update(Vector2f(0, -moveSpeed * 2), dt);
            } else if (it->getDirection() == "down") {
                it->update(Vector2f(0, moveSpeed * 2), dt);
            }
        }

        for (enemyIt = enemyList.begin(); enemyIt != enemyList.end(); enemyIt++) {
            enemyIt->update(dt, player.getPosition());
        }

        player.update(dt);

        window.clear();
        for (it = bulletList.begin(); it != bulletList.end(); it++) {
            it->draw(window);
        }
        for (enemyIt = enemyList.begin(); enemyIt != enemyList.end(); enemyIt++) {
            enemyIt->draw(window);
        }
        player.draw(window);
        window.display();
    }
    
    
    return 0;

}