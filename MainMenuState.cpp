#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window)
	: State(window)
{

	this->gameStateBTN = new Button(100, 100, 150, 50, &this->font, "Start Game", 
		sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), sf::Color(20, 20, 20, 200));
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);

}

MainMenuState::~MainMenuState()
{
	delete this->gameStateBTN;
}


void MainMenuState::endState()
{
	std::cout << "Ending GameState!" << std::endl;
}

void MainMenuState::updateKeybinds(const float& dt)
{
	this->checkForQuit();
	
}

void MainMenuState::update(const float& dt)
{
	this->updateKeybinds(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "A" << std::endl;

	this->gameStateBTN->update(this->mousePosView);
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->gameStateBTN->render(target);
}

