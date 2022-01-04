#include "bullet.hpp"

Bullet::Bullet(Vector2f origin, String direction) {
    // location = Vector2f(0, 0);
    bulletShape.setFillColor(Color::Yellow);
    location = origin;
    this->direction = direction;

    if (direction == "left" || direction == "right") {
        bulletShape.setSize(Vector2f(25, 5));
    } else if (direction == "up" || direction == "down") {
        bulletShape.setSize(Vector2f(5, 25));
    }
}

Bullet::~Bullet() {

}

void Bullet::update(Vector2f movement, Time dt) {
    location.x += movement.x * dt.asSeconds();
    location.y += movement.y * dt.asSeconds();

    bulletShape.setPosition(location);
}

void Bullet::draw(RenderWindow &window) {
    window.draw(bulletShape);
}

String Bullet::getDirection() {
    return this->direction;
}