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

void Sudoku::initMenuColor()
{
	this->menuColor = sf::Color(38, 45, 71);
	this->menuColor.a = 128;
}

void Sudoku::initStates()
{
	//this->states.push(new GameState(this->window));
	this->states.push(new MainMenuState(this->window));
}

//Load the background 
int Sudoku::bgLoader()
{
	if (!this->backgroundImg.loadFromFile("images/grid.jpg")) {
		std::cout << "Could not find the background image :(" << std::endl;
		return 1;
	}

	return 0;
}

//Constructor
Sudoku::Sudoku()
{
	this->initWindow();
	this->bgLoader();
	this->initMenuColor();
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

	//Render items
	sf::Sprite backgroundSprite(this->backgroundImg);
	this->window->draw(backgroundSprite);

	sf::RectangleShape rectangle(sf::Vector2f(308.f, 1080.f));
	rectangle.setFillColor(this->menuColor);
	this->window->draw(rectangle);

	if (!this->states.empty())
	{
		this->states.top()->render();
	}

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
