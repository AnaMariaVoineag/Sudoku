#include "MainMenuState.h"

MainMenuState::MainMenuState(sf::RenderWindow* window)
	: State(window)
{
	
	this->initFonts();
	this->initButtons();

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color::Magenta);

}

MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) 
	{
		delete it->second;
	}
}
void MainMenuState::initButtons()
{
	this->buttons["GAME_STATE"] = new Button(68, 185, 245, 45, &this->font,
		"How to play", sf::Color(70, 70, 70, 200), sf::Color(150, 150, 150, 255), 
		sf::Color(20, 20, 20, 200));

	this->buttons["EXIT_STATE"] = new Button(101, 240, 207, 50, &this->font,
		"Quit", sf::Color(100, 100, 100, 200), sf::Color(150, 150, 150, 255), 
		sf::Color(20, 20, 20, 200));
}

void MainMenuState::initFonts()
{
	if (!this->font.loadFromFile("fonts/Inria_Serif/InriaSerif-Regular.ttf"))
	{
		std::cout << "Could not load the font file!" << std::endl;
	}
}




void MainMenuState::endState()
{
	std::cout << "Ending GameState!" << std::endl;
}

void MainMenuState::updateButtons()
{
	for (auto &it : this->buttons) 
	{
		it.second->update(this->mousePosView);
	}

	//Quit the game
	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->endState();
	}
}

void MainMenuState::initKeybinds(const float& dt)
{
	this->checkForQuit();
	
}

void MainMenuState::update(const float& dt)
{
	this->updateMousePos();
	this->initKeybinds(dt);
	this->updateButtons();
	
}

void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	target->draw(this->background);
	this->renderButtons(target);
}

