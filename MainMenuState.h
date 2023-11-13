#pragma once

#include "HowToPlay.h"
#include "GameState.h"
#include "LoadGame.h"
#include "State.h"
#include "Button.h"

class MainMenuState :
    public State
{
public:
    MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);

    int selectedButton() {
        return selectedButtonIndex;
    }

    ~MainMenuState();

    //Functions
    void endState();
    void updateButtons(const float& dt);
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
    int selectedButtonIndex;
    float buttonChangeTimer;
  
    //Initialization
    void initMenuColor();
    void initFonts();
    void initButtons();
    void initKeybinds(const float& dt);
};