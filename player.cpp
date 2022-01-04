#include "player.hpp"


Player::Player() {
    position = Vector2f(20, 20);
    size = Vector2f(32, 32);
    playerRect.setSize(size);
    playerRect.setPosition(position);
    playerRect.setFillColor(Color::Red);
    speed = Vector2f(0, 0);
}

Player::~Player() {}

void Player::move(Vector2f moveSpeed) {
    speed = moveSpeed;
}

void Player::update(Time dt) {
    position.x += (speed.x * dt.asSeconds());
    position.y += (speed.y * dt.asSeconds());

    // std::cout << speed.x << " : " << speed.y << std::endl;


    playerRect.setPosition(position);
}

Vector2f Player::getPosition() {
    return position;
}

void Player::draw(RenderWindow &window) {
    window.draw(playerRect);
} 