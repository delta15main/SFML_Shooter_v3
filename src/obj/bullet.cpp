#include <SFML/Graphics.hpp>

#include "bullet.h"

void Bullet::setLive() {
    if ( isAlive ) { return; }
    if ( direction.x == 0 && direction.y == 0 ) { return; }
    isAlive = true;
    this->setHealth(1);
    this->SPAWN();
}

void Bullet::setDeath() {
    if ( !isAlive ) { return; }
    isAlive = false;
    this->setHealth(0);
}

void Bullet::setDirection(sf::Vector2f& targetPos) {
    float len = sqrt(targetPos.x * targetPos.x + targetPos.y * targetPos.y);
    direction = {targetPos.x / len, targetPos.y / len};
}

void Bullet::update() {
    if ( !isAlive ) { return; }
    if ( health <= 0 ) { this->setDeath(); }
    center = sprite.getPosition();
    radius = sprite.getGlobalBounds().size.x / 2.f;
    hText.update(sprite.getGlobalBounds(), std::to_string(health));
}
