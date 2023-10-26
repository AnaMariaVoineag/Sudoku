#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Sudoku");

    sf::Font font;
    if (!font.loadFromFile("fonts/Inria_Serif/InriaSerif-Regular.ttf")) {
        std::cout << "Could not find the font file" << std::endl;
        return 1;
    }

    Button btn1("Click me", font, { 200, 60 }, 40, sf::Color::White, sf::Color::Green);
    btn1.setPosition({ 40, 308 });

    // Load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("images/grid.jpg")) {
        std::cout << "Could not find the background image" << std::endl;
        return 1;
    }

    sf::Sprite backgroundSprite(backgroundTexture);

    sf::Color menuColor(38, 45, 71);
    menuColor.a = 128;

    // Load the "rules.png" image
    sf::Texture rulesTexture;
    if (!rulesTexture.loadFromFile("images/rules.png")) {
        std::cout << "Could not find the background image" << std::endl;
        return 1;
    }

    sf::Sprite rulesSprite(rulesTexture);

    bool showRules = false;

    while (window.isOpen()) {
        sf::Event Event;

        while (window.pollEvent(Event)) {
            switch (Event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                if (btn1.isMouseOver(window)) {
                    btn1.setFillColor(sf::Color::Green);
                }
                else {
                    btn1.setFillColor(menuColor);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (btn1.isMouseOver(window)) {
                    showRules = true;
                }
                break;
            }

            if (showRules) {
                sf::RenderWindow rulesWindow(sf::VideoMode(1332, 653), "How to Play");

                while (rulesWindow.isOpen()) {
                    sf::Event rulesEvent;

                    while (rulesWindow.pollEvent(rulesEvent)) {
                        if (rulesEvent.type == sf::Event::Closed) {
                            showRules = false;
                            rulesWindow.close();
                        }
                    }

                    rulesWindow.clear();
                    rulesWindow.draw(rulesSprite);
                    rulesWindow.display();
                }
            }
        }

        sf::RectangleShape rectangle(sf::Vector2f(308.f, 1080.f));
        rectangle.setFillColor(menuColor);

        window.clear();
        window.draw(backgroundSprite);
        window.draw(rectangle);
        btn1.drawTo(window);
        window.display();
    }

    return 0;
}
