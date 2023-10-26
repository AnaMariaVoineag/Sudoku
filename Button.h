class Button {
public:
    Button() {}
    Button(std::string t, sf::Font& font, int charSize, sf::Color textColor, sf::Color fillColor)
    {
        text.setString(t);
        text.setFillColor(textColor);
        text.setFont(font);
        text.setCharacterSize(charSize);
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

    void setPosition(sf::Vector2f position)
    {
        button.setPosition(position);
        text.setPosition(position.x + (button.getGlobalBounds().width - text.getGlobalBounds().width) / 2, position.y + (button.getGlobalBounds().height - text.getGlobalBounds().height) / 2);
    }

    void drawTo(sf::RenderWindow& window)
    {
        window.draw(button);
        window.draw(text);
    }

    bool isMouseOver(sf::RenderWindow& window)
    {
        sf::FloatRect buttonBounds = button.getGlobalBounds();
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        return buttonBounds.contains(static_cast<sf::Vector2f>(mousePosition));
    }

private:
    sf::RectangleShape button;
    sf::Text text;
};
