#pragma once

#include "State.h"

class GameState :
    public State
{
public:
    GameState(sf::RenderWindow* window);
    ~GameState();

    //Functions
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);

private:

};