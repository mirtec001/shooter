#include "enemy.hpp"
#include "helper.hpp"

using namespace sf;

Enemy::Enemy(Vector2f startingLocation, int speed) {
    enemyRect.setSize(Vector2f(32, 32));
    enemyRect.setFillColor(Color::Green);
    enemyRect.setPosition(startingLocation);
    this->speed = speed;
}

Enemy::~Enemy() {}

void Enemy::update(Time dt, Vector2f target) {
    Helper helper;
    enemyRect.setPosition(helper.Interpolate(enemyRect.getPosition(), target, (float)speed * dt.asSeconds()));
}

void Enemy::draw(RenderWindow &window) {
    window.draw(enemyRect);
}
