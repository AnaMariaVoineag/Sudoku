#include "HowToPlay.h"


HowToPlay::HowToPlay(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	initFonts();
	window->setTitle("How To Play");
	this->instructionsText.setFont(this->font);
	this->instructionsText.setCharacterSize(24);
	this->instructionsText.setFillColor(sf::Color::White);
	this->instructionsText.setString(" Instructions:\n 1 jucator\n GOAL: sa se puna numere in matricea de 9x9 astfel incat sa se regaseasca pe fiecare liniesi coloana toate numerele de la 1 la 9\n\n Cerinte:\n - sa se implementeze functionalitatea jocului\n - sa se creeze un meniu principal\n - sa se creeze un helper care sa ne explice regulile jocului\n - sa se contorizeze durata jocului\n - sa se stocheze numele jucatorului si timpul pana la castig\n - sa se poata stoca starea unui joc si sa putem continua jocul de unde am ramas\n - in cazul in are rezolvarea este gresita sa avem un helper care ne spune unde este greseala");

	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setFillColor(sf::Color(29, 34, 56));

	
}

HowToPlay::~HowToPlay()
{

}

void HowToPlay::initFonts()
{
	if (!this->font.loadFromFile("fonts/Inria_Serif/InriaSerif-Regular.ttf"))
	{
		std::cout << "Could not load the font file!" << std::endl;
	}
}


void HowToPlay::endState()
{
	std::cout << "Ending HowToPlay!" << std::endl;
}

void HowToPlay::updateInput(const float& dt)
{
	this->checkForQuit();

}

void HowToPlay::update(const float& dt)
{
	this->updateMousePos();
	this->updateInput(dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "B" << std::endl;
}

void HowToPlay::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	
	target->draw(this->background);
	target->draw(this->instructionsText);
	

}

