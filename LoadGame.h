#pragma once

#include "State.h"

class LoadGame :
    public State
{
public:
    LoadGame(sf::RenderWindow* window, std::stack<State*>* states);
    ~LoadGame();

    //Functions
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);

private:
    sf::RectangleShape background;

};