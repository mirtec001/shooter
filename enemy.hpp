#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
using namespace sf;

class Enemy {
    public:
        Enemy(Vector2f startingLocation, int speed);
        virtual ~Enemy();
        void update(Time dt, Vector2f target);
        void draw(RenderWindow &window);
    private:
        RectangleShape enemyRect;
        Vector2f location;
        Vector2f direction;
        int speed;
};

#endif //ENEMY_HPP