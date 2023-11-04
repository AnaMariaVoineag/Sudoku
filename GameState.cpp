#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::White);
}

GameState::~GameState()
{

}


void GameState::endState()
{
	std::cout << "Ending GameState!" << std::endl;
}

void GameState::updateInput(const float& dt)
{
	this->checkForQuit();

}

void GameState::update(const float& dt)
{
	this->updateMousePos();
	this->updateInput(dt);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "A" << std::endl;
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	
}
