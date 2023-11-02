#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "State.h"
#include "Button.h"

class MainMenuState :
    public State
{
public:
    MainMenuState(sf::RenderWindow* window);
    virtual ~MainMenuState();

    //Functions
    void endState();
    void updateKeybinds(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);

private:
    //Variabiles
    sf::RectangleShape background;
    sf::Font font;

    Button *gameStateBTN;

};

#endif


