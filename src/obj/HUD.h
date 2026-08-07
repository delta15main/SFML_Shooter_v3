#pragma once
#include <SFML/Graphics.hpp>

namespace HUD {
class HealthText {
protected:
    sf::Text text;
public:
    HealthText(sf::Font& font) : text(font, "") {
        text.setCharacterSize(20.f);
        text.setFillColor(sf::Color::White);
        text.setOutlineColor(sf::Color::Red);
    }
    void update(const sf::FloatRect& spriteRect, std::string str) {
        text.setString(str);
        text.setPosition({spriteRect.position.x + spriteRect.size.x / 2.f, spriteRect.position.y - spriteRect.size.y / 2.f});
        text.setOrigin(text.getGlobalBounds().size / 2.f);
    }
    virtual void draw(sf::RenderWindow& win) {
        win.draw(text);
    }
};

//class TextOnWindow : public HealthText {
//public:
//    TextOnWindow(sf::Font& font) : HealthText(font) {}
//    void update(const sf::Vector2u& winSize, std::string str) {
//        text.setString(str);
//        sf::Vector2f tmp;
//        tmp.x = (winSize.x / 95.f) + (text.getGlobalBounds().size.x / 2.f);
//        tmp.y = (winSize.y - (winSize.y / 95.f)) - (text.getGlobalBounds().size.y / 2.f);
//        text.setPosition(tmp);
//        text.setOrigin(text.getGlobalBounds().size / 2.f);
//    }
//};
}
