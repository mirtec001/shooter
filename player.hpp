#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Player {

public:
    Player(sf::Vector2f position);
    ~Player();
    void move(Vector2f moveSpeed);
    void update(Time dt);
    void draw(RenderWindow &window);
    Vector2f getPosition();
private:
    RectangleShape playerRect;
    Vector2f position;
    Vector2f size; 
    Vector2f speed;
};

#endif //PLAYER_HPP