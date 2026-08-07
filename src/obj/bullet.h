#pragma once
#include <SFML/Graphics.hpp>

#include "entity.h"


class Bullet : public Entity {
protected:
    sf::Vector2f direction;
    virtual void SPAWN() = 0;

public:
    Bullet(const sf::Texture& texture, int heal, float vel, sf::Font& font) :
        Entity(texture, heal, vel, font) {}
    virtual ~Bullet() = default;

    // Get
    virtual bool        isEnemy()               override    { return 0; }
    virtual bool        isBullet()              override    { return 1; }
    virtual bool        isPlayer()              override    { return 0; }

    // Set
    virtual void        setLive()               override final;
    virtual void        setDeath()              override final;
    virtual void        setDirection(sf::Vector2f& targetPos) final;

    // Logics
    virtual void        update()                override;
};
