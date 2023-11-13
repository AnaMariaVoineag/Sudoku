#include "LoadGame.h"

LoadGame::LoadGame(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	window->setTitle("Sudoku");

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color(29, 34, 56));
}

LoadGame::~LoadGame()
{

}


void LoadGame::endState()
{
	std::cout << "Ending LoadGame!" << std::endl;
}

void LoadGame::updateInput(const float& dt)
{
	this->checkForQuit();

}

void LoadGame::update(const float& dt)
{
	this->updateInput(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "A" << std::endl;
}

void LoadGame::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);

}