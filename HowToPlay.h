#pragma once

#include "State.h"
#include "MainMenuState.h"
#include <fstream>

class HowToPlay :
    public State
{
public:
    HowToPlay(sf::RenderWindow* window, std::stack<State*>* states);
    ~HowToPlay();

    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);

    //Initializer
    void initFonts();

    void bgLoader();

    void photosLoader();

private:
    sf::Text instructionsText;
    sf::Font font;
    sf::Texture backgroundImg;
    sf::Texture photos;

};