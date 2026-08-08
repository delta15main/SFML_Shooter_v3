#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <random>

#include "entity.h"

class Enemy : public Entity {
protected:
    std::random_device              rd;
    std::mt19937                    gen;
    std::uniform_int_distribution<int>      distH;
    std::uniform_real_distribution<float>   distV, distP;

    virtual void SPAWN() = 0;
public:
    Enemy(const sf::Texture& texture, int heal, float vel, sf::Font& font) :
        Entity(texture, heal, vel, font),
        gen(rd()),
        distH(heal - 10, heal),
        distV(vel / 2.f, vel ),
        distP(0.f, MAX_SIZE)    {}
    virtual ~Enemy() = default;

    // Get
    virtual bool        isEnemy()               override    { return 1; }
    virtual bool        isBullet()              override    { return 0; }
    virtual bool        isPlayer()              override    { return 0; }

    // Set
    virtual void        setLive()               override final;
    virtual void        setDeath()              override final;
    virtual void        setVelocity(float vel)  final;

    // Logics
    virtual void        move(const sf::Vector2f& targetPos, float deltaTime) override;
    virtual void        update()                override;
};
