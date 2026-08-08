#include <SFML/Graphics.hpp>

#include "bullet.h"

void Bullet::setLive() {
    if ( isAlive ) { return; }
    if ( direction.x == 0 && direction.y == 0 ) { return; }
    isAlive = true;
    this->setHealth(1);
    // this->SPAWN();
}

void Bullet::setDeath() {
    if ( !isAlive ) { return; }
    isAlive = false;
    this->setHealth(0);
}

sf::Vector2f Bullet::setDirection(sf::Vector2f& playerPos, sf::Vector2f& targetPos) {
    sf::Vector2f newDir = targetPos - playerPos;
    float len = sqrt(newDir.x * newDir.x + newDir.y * newDir.y);
    direction = {newDir.x / len, newDir.y / len};
    return direction;
}

void Bullet::update() {
    if ( !isAlive ) { return; }
    if ( health <= 0 ) { this->setDeath(); }
    center = sprite.getPosition();
    radius = sprite.getGlobalBounds().size.x / 2.f;
    hText.update(sprite.getGlobalBounds(), std::to_string(health));
}
