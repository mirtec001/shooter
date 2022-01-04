#ifndef BULLET_HPP
#define BULLET_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet {

public:
    Bullet(Vector2f origin, String direction);
    ~Bullet();
    void update(Vector2f movement, Time dt);
    void draw(RenderWindow &window);
    String getDirection();
    

private:
    RectangleShape bulletShape;
    Vector2f location;
    String direction;
};

#endif //BULLET_HPP