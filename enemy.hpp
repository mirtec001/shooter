#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <SFML/Graphics.hpp>
using namespace sf;

class Enemy {
    public:
        Enemy(Vector2f startingLocation);
        virtual ~Enemy();
        void update(Time dt);
        void draw(RenderWindow &window);
    private:
        RectangleShape enemyRect;
        Vector2f location;
        Vector2f direction;
};

#endif //ENEMY_HPP