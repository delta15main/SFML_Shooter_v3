#pragma once
#include <SFML/Graphics.hpp>
struct Hitbox {
    sf::Vector2f center;
    float radius;

    static Hitbox makeCircle(const sf::Vector2f& cent, const float& rad) { return {cent, rad}; }

    bool intersects(const Hitbox& other) const {
        sf::Vector2f delta = center - other.center;
            float distSqr = delta.x * delta.x + delta.y * delta.y;
            float radSum = radius + other.radius;
            return distSqr < (radSum * radSum);
    }
};
