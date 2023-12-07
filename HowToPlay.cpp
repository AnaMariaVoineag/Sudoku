#include "HowToPlay.h"


HowToPlay::HowToPlay(sf::RenderWindow* window, std::stack<State*>* states)
	: State(window, states)
{
	initFonts();
	bgLoader();
	photosLoader();
	window->setTitle("How To Play");
	this->instructionsText.setFont(this->font);
	this->instructionsText.setCharacterSize(32);
	this->instructionsText.setFillColor(sf::Color::White);
	std::string s = " - Start with a 9x9 grid, divided into nine 3x3 subgrids called regions or " 
	"boxes.Each box is further divided into 3x3 cells, making a total of 81 cells in the entire grid.\n"
	" - Fill in the grid with the numbers 1 through 9. Each row, column, and region must contain all of the numbers from 1 to 9 without repetition.\n - If some numbers are already filled in, you cannot change them.\n - No row, column, or region can have repeated numbers.Each number must appear only once in each row, column, and region.\n - Solve the puzzle using logic and deduction.You don't need to guess. If you reach a point where you have to guess, then you may have made a mistake.";
		this->instructionsText.setString(s);
	this->instructionsText.move(sf::Vector2f(190.f, 99.f));
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

void HowToPlay::photosLoader()
{
	if (!this->photos.loadFromFile("images/grid.jpg"))
	{
		std::cout << "Could not find the background image :(" << std::endl;
	}

	if (!this->photos.loadFromFile("images/dwight.png"))
	{
		std::cout << "Could not find the background image :(" << std::endl;
	}
}

void HowToPlay::bgLoader()
{
	if (!this->backgroundImg.loadFromFile("images/grid.jpg"))
	{
		std::cout << "Could not find the background image :(" << std::endl;
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

	// Draw the background
	sf::Sprite backgroundSprite(this->backgroundImg);
	this->window->draw(backgroundSprite);

	sf::Sprite imageSprite(this->photos);

	// Set the desired width and height
	float desiredWidth = 1711.532f;
	float desiredHeight = 1241.048f;

	// Get the original width and height of the texture
	float originalWidth = 666.f;
	float originalHeight = 375.f;

	// Scale the image to match the desired dimensions
	imageSprite.setScale(desiredWidth / originalWidth, desiredHeight / originalHeight);

	// Rotate the sprite
	float rotationAngle = -0.513f;
	imageSprite.rotate(rotationAngle);

	// Create an sf::RectangleShape
	sf::RectangleShape shape(sf::Vector2f(desiredWidth, desiredHeight));
	shape.setPosition(sf::Vector2f(67.f, 179.f));  // Adjust as needed

	// Set the position of the sprite relative to the center of the shape
	imageSprite.setPosition(
		shape.getPosition().x + (shape.getGlobalBounds().width - imageSprite.getGlobalBounds().width) / 2.f,
		shape.getPosition().y + (shape.getGlobalBounds().height - imageSprite.getGlobalBounds().height) / 2.f
	);

	this->window->draw(imageSprite);

	// Draw the text on top of the image
	target->draw(this->instructionsText);
}


