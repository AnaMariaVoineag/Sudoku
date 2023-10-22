#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Sudoku");

    // Load the background image
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("images/grid.jpg"))
    {
        std::cout << "Could not find the background image" << std::endl;
        return 1; // Return an error code
    }

    // Create a sprite for the background
    sf::Sprite backgroundSprite(backgroundTexture);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Convert the hex color to RGB
        sf::Color menuColor(38, 45, 71);

        sf::RectangleShape rectangle(sf::Vector2f(308.f, 1080.f));
        rectangle.setFillColor(menuColor);

        window.clear();

        // Draw the background image first
        window.draw(backgroundSprite);

        // Draw the menu rectangle
        window.draw(rectangle);

        window.display();
    }

    return 0;
}
