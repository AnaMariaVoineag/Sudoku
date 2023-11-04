#pragma once

#include "GameState.h"
#include "State.h"
#include "Button.h"

class MainMenuState :
    public State
{
public:
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
    ~MainMenuState();

    //Functions
    void endState();
    void updateButtons();
    void bgLoader();
    void update(const float& dt);
    void renderButtons(sf::RenderTarget* target = NULL);
    void render(sf::RenderTarget* target = NULL);

private:
    //Variabiles
    sf::Font font;
    sf::Texture backgroundImg;
    sf::Color menuColor;

    std::map<std::string, Button*> buttons;

    //Initialization
    void initMenuColor();
    void initFonts();
    void initButtons();
    void initKeybinds(const float& dt);
};