#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED};

class Button {
public:
    Button(float x, float y, float width, float height, sf::Font* font, 
    std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color pressedColor, unsigned int textSize);
    ~Button();

    //Accessors
    const bool isPressed() const;

    //Functions
    void update(const sf::Vector2f mousePos);
    void render(sf::RenderTarget* target);

private:
    short unsigned buttonState;
    unsigned int textSize;

    sf::RectangleShape shape;
    sf::Font *font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color pressedColor;
};

