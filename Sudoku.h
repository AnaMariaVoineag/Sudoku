#ifndef SUDOKU_H
#define SUDOKU_H

#include "GameState.h"

class Sudoku
{
public:
	Sudoku();
	virtual ~Sudoku();

	//Functions
	void updateDt();
	void updateSFMLEvents();
	void update();
	int bgLoader();
	void render();
	void run();
	void endApplication();

private:
	//Variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::Texture backgroundImg;
	sf::Color menuColor;

	sf::Clock dtClock; 
	float dt;

	std::stack<State*> states; ///State is an abstract class

	//Initialization
	void initMenuColor();
	void initWindow();
	void initStates();

};

#endif
