#pragma once
#include <SFML/Graphics.hpp>

#include "enemy.h"

class Goblin : public Enemy {
private:
    static sf::Vector2f StartPos;
    static int Num;
    static bool isSpawn;
    void SPAWN() override {
    }

public:
    Goblin(const sf::Texture& texture, sf::Font& font) :
        Enemy(texture, 10, 0.f, font) {
            ++Num;
            if (Num >= MAX_GOB) { StartPos = {distP(gen), distP(gen)}; }
        }
    void update() override {
        if ( !isSpawn ) { ::
        if ( !isAlive ) { return; }
        if ( health <= 0 ) { this->setDeath(); }
        center = sprite.getPosition();
        radius = sprite.getGlobalBounds().size.x / 2.f;
        hText.update(sprite.getGlobalBounds(), std::to_string(health)); 
    }
};
