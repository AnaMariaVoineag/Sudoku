#include "HowToPlay.h"


HowToPlay::HowToPlay(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	initFonts();
	window->setTitle("How To Play");
	this->instructionsText.setFont(this->font);
	this->instructionsText.setCharacterSize(24);
	this->instructionsText.setFillColor(sf::Color::White);
	this->instructionsText.setString(" Sudoku Rules:\n - Start with a 9x9 grid, divided into nine 3x3 subgrids called regions or boxes. Each box is further divided into 3x3 cells, making a total of 81 cells in the entire grid.\n - Fill in the grid with the numbers 1 through 9. Each row, column, and region must contain all of the numbers from 1 to 9 without repetition.\n - If some numbers are already filled in, you cannot change them.\n - No row, column, or region can have repeated numbers. Each number must appear only once in each row, column, and region.\n - Solve the puzzle using logic and deduction. You don't need to guess. If you reach a point where you have to guess, then you may have made a mistake.");

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
	//this->updateMousePos();
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

