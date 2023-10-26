#include <SFML/Graphics.hpp>
#include <iostream>

// Function to center text within a bounding rectangle
void centerText(sf::Text& text, const sf::FloatRect& bounds)
{
    float centerX = bounds.left + (bounds.width - text.getLocalBounds().width) / 2;
    float centerY = bounds.top + bounds.height / 2 - text.getLocalBounds().height / 2;
    text.setPosition(centerX, centerY);
}

// Function to create an sf::Text object
sf::Text createText(const std::string& str, const sf::Font& font, int characterSize, float x, float y)
{
    sf::Text text;
    text.setFont(font);
    text.setString(str);
    text.setCharacterSize(characterSize);
    text.setPosition(x, y);
    return text;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Sudoku");

    sf::Font font;
    if (!font.loadFromFile("fonts/Inria_Serif/InriaSerif-Regular.ttf")) {
        std::cout << "Could not find the font file" << std::endl;
        return 1;
    }

    sf::Text textHTP = createText("How to play", font, 40, 40.f, 180.f);
    sf::FloatRect textHTPBounds = textHTP.getGlobalBounds();
    centerText(textHTP, textHTPBounds);

    sf::FloatRect menuSpaceLine = textHTP.getGlobalBounds();
    menuSpaceLine.left = 40.f;
    menuSpaceLine.width = 308.f;

    sf::FloatRect textHTPBoundsCentered = textHTP.getGlobalBounds();
    centerText(textHTP, textHTPBoundsCentered);

    float centerXSpaceLine = menuSpaceLine.left + menuSpaceLine.width / 2;

    sf::Text textText1 = createText("Text1", font, 32, centerXSpaceLine - textHTPBoundsCentered.width / 2, textHTP.getPosition().y + textHTPBounds.height + 20);

    sf::Text textText2 = createText("Text2", font, 32, centerXSpaceLine - textHTPBoundsCentered.width / 2, textText1.getPosition().y + textText1.getLocalBounds().height + 20);

    // Load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("images/grid.jpg")) {
        std::cout << "Could not find the background image" << std::endl;
        return 1;
    }

    sf::Sprite backgroundSprite(backgroundTexture);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseMoved) {
                if (textHTP.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)) ||
                    textText1.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y)) ||
                    textText2.getGlobalBounds().contains(sf::Vector2f(event.mouseMove.x, event.mouseMove.y))) {
                    // Change the text color or other properties to indicate the mouse is over them
                    textHTP.setFillColor(sf::Color::White);
                    textText1.setFillColor(sf::Color::White);
                    textText2.setFillColor(sf::Color::White);
                }
                else {
                    // Restore the original text color or properties
                    textHTP.setFillColor(sf::Color::Black);
                    textText1.setFillColor(sf::Color::Black);
                    textText2.setFillColor(sf::Color::Black);
                }
            }
        }

        sf::Color menuColor(38, 45, 71);
        menuColor.a = 128;

        sf::RectangleShape rectangle(sf::Vector2f(308.f, 1080.f));
        rectangle.setFillColor(menuColor);

        window.clear();
        window.draw(backgroundSprite);
        window.draw(rectangle);
        window.draw(textHTP);
        window.draw(textText1);
        window.draw(textText2);
        window.display();
    }

    return 0;
}
