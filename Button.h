#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
public:
    Button() {}
    Button(std::string t, sf::Font& font, sf::Vector2f size, int charSize, sf::Color textColor, sf::Color fillColor)
    {
        text.setString(t);
        text.setFillColor(textColor);
        text.setFont(font);
        text.setCharacterSize(charSize);
        //******************************//
        button.setSize(size);
        button.setFillColor(fillColor);
    }

    void setTextColor(sf::Color color)
    {
        text.setFillColor(color);
    }

    void setFillColor(sf::Color color)
    {
        button.setFillColor(color);
    }

    void setSize(sf::Vector2f size)
    {
        button.setSize(size);
    }

    void setPosition(sf::Vector2f pos)
    {
        button.setPosition(pos);

        float xPos = (pos.x + button.getLocalBounds().width / 2) - (text.getLocalBounds().width / 2);
        float yPos = (pos.y + button.getLocalBounds().height / 2) - (text.getLocalBounds().height / 2);
        text.setPosition({ xPos, yPos });
    }

    void drawTo(sf::RenderWindow& window)
    {
        window.draw(button);
        window.draw(text);
    }

    bool isMouseOver(sf::RenderWindow& window)
    {
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        float btnPosX = button.getPosition().x;
        float btnPosY = button.getPosition().y;

        float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
        float btnxPosheight = button.getPosition().y + button.getLocalBounds().height;

        if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnxPosheight && mouseY > btnPosY)
        {
            return true;
        }
        return false;
    }

private:
    sf::RectangleShape button;
    sf::Text text;
};
