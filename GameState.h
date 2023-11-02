#ifndef GAMESTATE.H
#define GAMESTATE_H

#include "State.h"

class GameState :
    public State
{
public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    //Functions
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = NULL);

private:

};


#endif 

