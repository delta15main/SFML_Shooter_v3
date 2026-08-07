#pragma once
#include <SFML/Graphics.hpp>

#include "../gam/game.h"
#include "hitbox.h"
#include "HUD.h"

class Entity {
protected:
    sf::Sprite sprite;
    sf::Vector2f center;
    float radius, velocity;
    bool isAlive;
    int health;
    HUD::HealthText hText;
    
public:
    Entity(const sf::Texture& texture, int heal, float vel, sf::Font& font) :
        sprite(texture),
        health(0),
        velocity(vel),
        isAlive(false),
        hText(font)      {
            sprite.setOrigin({sprite.getGlobalBounds().size.x / 2.f, sprite.getGlobalBounds().size.y / 2.f});
        }
    virtual ~Entity() = default;
    // Get
    virtual Hitbox  getHitbox()         final       { return Hitbox::makeCircle(center, radius); }
    virtual int     getHealth()         final       { return health; }
    virtual bool    getAlive()          final       { return isAlive; }
    virtual bool    isEnemy()           = 0;
    virtual bool    isBullet()          = 0;
    virtual bool    isPlayer()          = 0;

    // Set
    virtual void    setLive() = 0;
    virtual void    setDeath() = 0;
    virtual void    setHealth(int heal) final      { health = heal; }

    // Logics
    virtual void    move(const sf::Vector2f& targetPos, float deltaTime) = 0;
    virtual void    update() = 0;
    virtual void    draw(sf::RenderWindow& window) final { if ( isAlive ) { window.draw(sprite);
                                                                            hText.draw(window); } }

};
