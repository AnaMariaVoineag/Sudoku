#pragma once

#include "MainMenuState.h"

class Sudoku
{
public:
	Sudoku();
	~Sudoku();

	//Functions
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
	void endApplication();

private:
	//Variables
	sf::RenderWindow* window;
	sf::Event event;
	

	sf::Clock dtClock; 
	float dt;

	std::stack<State*> states; ///State is an abstract class

	//Initialization
	void initWindow();
	void initStates();


};