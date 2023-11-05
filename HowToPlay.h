#pragma once

#include "State.h"
#include <fstream>

class HowToPlay :
    public State
{
public:
    HowToPlay(sf::RenderWindow* window, std::stack<State*>* states);
    ~HowToPlay();

    //Functions
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);
    void fileReader();

    //Initializer
    void initFonts();

private:
    sf::RectangleShape background;
    sf::Text instructionsText;
    sf::Font font;

};