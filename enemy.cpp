#include "enemy.hpp"


Enemy::Enemy(Vector2f startingLocation) {
    enemyRect.setSize(Vector2f(32, 32));
    enemyRect.setFillColor(Color::Green);
    enemyRect.setPosition(startingLocation);
}

Enemy::~Enemy() {}

void Enemy::update(Time dt) {

}

void Enemy::draw(RenderWindow &window) {
    window.draw(enemyRect);
}
