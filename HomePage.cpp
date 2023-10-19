#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Sudoku");

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Convert the hex color to RGB
        sf::Color backgroundColor(29, 34, 56);
        sf::Color menuColor(38, 45, 71);

        //sf::RectangleShape rectangle(sf::Vector2f(308.f, 1080.f));
        rectangle.setFillColor(menuColor);
        window.clear(backgroundColor);

        window.draw(rectangle);
        window.display();
    }

    return 0;
}
