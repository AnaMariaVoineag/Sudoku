#include "Sudoku.h"

//Static functions

//Initializer functions
void Sudoku::initWindow()
{
	std::ifstream fileWindow("Config/window.ini");

	std::string title = "None";
	sf::VideoMode windowBounds(1920, 1080);
	unsigned framerateLimit = 120;
	bool verticalSynchEnabled = false;

	if (fileWindow.is_open())
	{
		std::getline(fileWindow, title);
		fileWindow >> windowBounds.width >> windowBounds.height;
		fileWindow >> framerateLimit;
		fileWindow >> verticalSynchEnabled;
	}

	fileWindow.close();

	this->window = new sf::RenderWindow(sf::VideoMode(windowBounds), title);
	this->window->setFramerateLimit(framerateLimit);
	this->window->setVerticalSyncEnabled(verticalSynchEnabled);
}


void Sudoku::initStates()
{
	
	this->states.push(new MainMenuState(this->window, &this->states));
}



//Constructor
Sudoku::Sudoku()
{
	this->initWindow();
	this->initStates();
}

//Destructor
Sudoku::~Sudoku()
{
	delete this->window;

	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}

}

//Functions
void Sudoku::updateDt()
{
	/*Updates the dt variable with the it takes to update and render one frame*/
	this->dt = this->dtClock.restart().asSeconds();
}

void Sudoku::updateSFMLEvents()
{
	while (this->window->pollEvent(this->event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}

void Sudoku::update()
{
	this->updateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);
		if (this->states.top()->getQuit())
		{
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	//End of the application
	else {
		this->endApplication();
		this->window->close();
	}
}

void Sudoku::render()
{
	this->window->clear();

	if (!this->states.empty())
	{
		this->states.top()->render();
	}

	//this->window->draw(this->background);
	this->window->display();
	
}

void Sudoku::run()
{
	while (this->window->isOpen())
	{
		this->updateDt();
		this->update();
		this->render();
	}
}

void Sudoku::endApplication()
{
	std::cout << "Ending Application!" << std::endl;
}
