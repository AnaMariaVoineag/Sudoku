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

    // Use the createText function to create text items
    sf::Text textHTP = createText("How to play", font, 40, 40.f, 180.f);
    sf::FloatRect textHTPBounds = textHTP.getGlobalBounds();
    centerText(textHTP, textHTPBounds);

    // Calculate the bounding rectangle for the menu space line
    sf::FloatRect menuSpaceLine = textHTP.getGlobalBounds();
    menuSpaceLine.left = 40.f;
    menuSpaceLine.width = 308.f;

    // Calculate new bounds for textHTP after centering
    sf::FloatRect textHTPBoundsCentered = textHTP.getGlobalBounds();
    centerText(textHTP, textHTPBoundsCentered);

    // Calculate the center of the menu space line
    float centerXSpaceLine = menuSpaceLine.left + menuSpaceLine.width / 2;

    sf::Text textNG = createText("New Game", font, 24, centerXSpaceLine - textHTPBoundsCentered.width / 2, textHTP.getPosition().y + textHTPBounds.height + 20);
    sf::Text textLG = createText("Load Game", font, 24, centerXSpaceLine - textHTPBoundsCentered.width / 2, textNG.getPosition().y + textNG.getLocalBounds().height + 20);
    sf::Text textMG = createText("Music Genre", font, 24, centerXSpaceLine - textHTPBoundsCentered.width / 2, textLG.getPosition().y + textLG.getLocalBounds().height + 20);
    sf::Text textYC = createText("Your Content", font, 24, centerXSpaceLine - textHTPBoundsCentered.width / 2, textMG.getPosition().y + textMG.getLocalBounds().height + 20);
    sf::Text textSettings = createText("Your Settings", font, 24, centerXSpaceLine - textHTPBoundsCentered.width / 2, textYC.getPosition().y + textYC.getLocalBounds().height + 20);

    // Load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("images/grid.jpg")) {
        std::cout << "Could not find the background image" << std::endl;
        return 1; 
    }

    // Create a sprite for the background
    sf::Sprite backgroundSprite(backgroundTexture);

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Convert the hex color to RGB
        sf::Color menuColor(38, 45, 71);

        menuColor.a = 128; // Set alpha to 128 for semi-transparency

        sf::RectangleShape rectangle(sf::Vector2f(308.f, 1080.f));
        rectangle.setFillColor(menuColor);

        window.clear();

        // Draw the background image first
        window.draw(backgroundSprite);

        // Draw the menu rectangle
        window.draw(rectangle);

        // Display the text
        window.draw(textHTP);
        window.draw(textNG);
        window.draw(textLG);
        window.draw(textMG);
        window.draw(textYC);
        window.draw(textSettings);
        window.display();

    }

    return 0;
}
