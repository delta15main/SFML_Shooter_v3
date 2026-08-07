#include <SFML/Graphics.hpp>
#include <random>

#include "enemy.h"

// Set
void Enemy::setLive() {
    if ( isAlive ) { return; }
    isAlive = true;
    this->setHealth(distH(gen));
    this->setVelocity(distV(gen));
    this->SPAWN();
}

void Enemy::setDeath() {
    if ( !isAlive ) { return; }
    isAlive = false;
    this->setHealth(0);
}

void Enemy::setVelocity(float vel) {
    velocity = vel;
}

// Logics
void Enemy::move(const sf::Vector2f& targetPos, float deltaTime) {
    sf::Vector2f newPos{targetPos.x - sprite.getPosition().x, targetPos.y - sprite.getPosition().y};
    float length = sqrt(newPos.x * newPos.x + newPos.y * newPos.y);
    if ( length >= 0.0001f ) { newPos /= length; }
    else { newPos = {0.f, 0.f}; }
    sprite.move(newPos * velocity * deltaTime);

}

void Enemy::update() {
    if ( !isAlive ) { return; }
    if ( health <= 0 ) { this->setDeath(); }
    center = sprite.getPosition();
    radius = sprite.getGlobalBounds().size.x / 2.f;
    hText.update(sprite.getGlobalBounds(), std::to_string(health));
}
