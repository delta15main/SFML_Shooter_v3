#pragma once
#include <SFML/Graphics.hpp>

#include "../bullet.h"

class Cartridge final : public Bullet {
private:

public:
    Cartridge(const sf::Texture& texture, sf::Font& font) : Bullet(texture, 1, 0.7f, font) {}
    ~Cartridge() = default;

    void move(const sf::Vector2f& targetPos, float deltaTime) override {
         if ( !isAlive ) { return; }
         sprite.move(targetPos * velocity * deltaTime);
    }

};
