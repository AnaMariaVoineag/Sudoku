#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <stack>
#include <map>

#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "SFML\Network.hpp"

class State
{
public:
	State(sf::RenderWindow* window);
	virtual ~State();

	const bool& getQuit() const;

	virtual void checkForQuit();
	virtual void endState() = 0;

	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

	sf::Vector2u mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2i mousePosView;

private:

};
#endif
