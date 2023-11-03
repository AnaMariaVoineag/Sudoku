#pragma once

#include "GameState.h"
#include "State.h"
#include "Button.h"

class MainMenuState :
    public State
{
public:
    MainMenuState(sf::RenderWindow* window);
    ~MainMenuState();

    //Functions
    void endState();
    void updateButtons();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target = NULL);
    void render(sf::RenderTarget* target = NULL);

private:
    //Variabiles
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*> buttons;

    void initFonts();
    void initButtons();
    void initKeybinds(const float& dt);
};