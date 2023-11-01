#include "State.h"

//Contructor
State::State(sf::RenderWindow* window)
{
	this->window = window;
	this->quit = false;

}

//Destructor
State::~State()
{

}

const bool& State::getQuit() const
{
	return this->quit;
}

void State::checkForQuit()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}

void State::endState()
{
}

