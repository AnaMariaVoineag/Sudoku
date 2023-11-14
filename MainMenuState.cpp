#include "MainMenuState.h"
#include "Sudoku.h"


MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states), selectedButtonIndex(0), buttonChangeTimer(0.0f) 
{

	this->window->setTitle("Main Menu");
	this->initFonts();
	this->initButtons();
	this->bgLoader();
	this->initMenuColor();
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
	this->buttons["HOW_TO_PLAY"] = new Button(70, 185, 170, 45, &this->font,
		"How to play", sf::Color(29, 34, 56), sf::Color(sf::Color::Magenta),
		sf::Color(20, 20, 20, 200), 30);

	this->buttons["NEW_GAME"] = new Button(100, 240, 121, 34, &this->font,
		"New Game", sf::Color(29, 34, 56), sf::Color(sf::Color::Magenta),
		sf::Color(20, 20, 20, 200), 24);

	this->buttons["LOAD_GAME"] = new Button(100, 285, 126, 34, &this->font,
		"Load Game", sf::Color(29, 34, 56), sf::Color(sf::Color::Magenta),
		sf::Color(20, 20, 20, 200), 24);
}

//Load the background 
void MainMenuState::bgLoader()
{
	if (!this->backgroundImg.loadFromFile("images/grid.jpg")) 
	{
		std::cout << "Could not find the background image :(" << std::endl;
	}
}

void MainMenuState::initMenuColor()
{
	this->menuColor = sf::Color(38, 45, 71);
	this->menuColor.a = 128;
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
	std::cout << "Ending MainMenuState!" << std::endl;
}

void MainMenuState::updateButtons(const float& dt)
{
	// Define a time delay between button changes (in seconds)
	static const float BUTTON_CHANGE_DELAY = 0.2f;

	// Update the button change timer
	buttonChangeTimer += dt;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && buttonChangeTimer > BUTTON_CHANGE_DELAY)
	{
		if (selectedButtonIndex < buttons.size() - 1)
			selectedButtonIndex++;
		else
			selectedButtonIndex = 0;

		// Reset the timer
		buttonChangeTimer = 0.0f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && buttonChangeTimer > BUTTON_CHANGE_DELAY)
	{

		if (selectedButtonIndex > 0)
			selectedButtonIndex--;
		else
			selectedButtonIndex = buttons.size() - 1; // Wrap to the last button

		// Reset the timer
		buttonChangeTimer = 0.0f;
	}

	// Handle enter/return key press
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) || sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		switch (selectedButtonIndex)
		{
		case 0:
			this->states->push(new HowToPlay(this->window, this->states));
			break;
		case 1:
			this->states->push(new GameState(this->window, this->states));
			break;
		case 2:
			this->states->push(new LoadGame(this->window, this->states));
			break;
		}
	}
}




void MainMenuState::renderButtons(sf::RenderTarget* target)
{
	size_t index = 0;
	for (auto& it : this->buttons)
	{
		it.second->setHoverColor(selectedButtonIndex == index);
		it.second->render(target);

		index++;
	}
}


void MainMenuState::initKeybinds(const float& dt)
{
	this->checkForQuit();
	
}

void MainMenuState::update(const float& dt)
{
	//this->updateMousePos();
	this->initKeybinds(dt);
	this->updateButtons(dt);
	
}



void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->window;

	//Render items
	sf::Sprite backgroundSprite(this->backgroundImg);
	this->window->draw(backgroundSprite);

	sf::RectangleShape rectangle(sf::Vector2f(308.f, 1080.f));
	rectangle.setFillColor(this->menuColor);
	this->window->draw(rectangle);
	

	this->renderButtons(target);
}

