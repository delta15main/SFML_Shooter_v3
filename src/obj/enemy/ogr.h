#pragma once
#include <SFML/Graphics.hpp>

#include "../enemy.h"

class Ogr final : public Enemy {
private:
    static bool isSpawn;
    static int spawned;
    bool isSpawned;
    sf::Clock start;
    void SPAWN() override {
        sprite.setPosition({distP(gen), distP(gen)});
    }
public:
    Ogr(const sf::Texture& texture, sf::Font& font) : Enemy(texture, 30, 0.2f, font), isSpawned(false) {
        this->SPAWN();
        ++spawned;
        if ( spawned >= 3 ) { isSpawn = true; }
    }
    ~Ogr() = default;

    // Logics
    void move(const sf::Vector2f& targetPos, float deltaTime) override {
        if ( !isSpawn ) { return; }
        if ( start.getElapsedTime().asSeconds() <= 3.f ) { return; }
        sf::Vector2f newPos{targetPos.x - sprite.getPosition().x, targetPos.y - sprite.getPosition().y};
        float length = sqrt(newPos.x * newPos.x + newPos.y * newPos.y);
        if ( length >= 0.0001f ) { newPos /= length; }
        else { newPos = {0.f, 0.f}; }
        sprite.move(newPos * velocity * deltaTime);
    }
    void update() override {
        if ( !isAlive ) { return; }
        if ( health <= 0 ) { this->setDeath(); --spawned; }
        if ( spawned <= 0 ) { isSpawn = false; }
        if ( isSpawn && !isSpawned ) { this->setLive(); start.reset(); }
        if ( start.getElapsedTime().asSeconds() >= 3.f ) {
            center = sprite.getPosition();
            radius = sprite.getGlobalBounds().size.x / 2.f;
            hText.update(sprite.getGlobalBounds(), std::to_string(health));
        } else {
            center = {0.f, 0.f};
            radius = 0.f;
            hText.update(sprite.getGlobalBounds(), std::to_string(health));
        }
    }

};
