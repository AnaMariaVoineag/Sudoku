#pragma once

#include "State.h"

class GameState :
    public State
{
public:
    GameState(sf::RenderWindow* window, std::stack<State*>* states);
    ~GameState();

    // Functions
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr) override;

    bool isValidSudoku(const int sudoku[9][9], int row, int col, int num);
    bool isNumberValid(const int sudoku[9][9], int row, int col, int num);
    void drawGrid(sf::RenderWindow& window, int mapW, int mapH, float tileSize, int selectedTileX, int selectedTileY);
    void handleInput(sf::Event::TextEvent textEvent, sf::String& currentInput, int& selectedTileValue, int sudoku[9][9], int selectedTileX, int selectedTileY);
private:
    sf::RectangleShape background;

    int sudoku[9][9] = {};
    int selectedTileX = 0;
    int selectedTileY = 0;
    int selectedTileValue = 0;

    sf::String currentInput;
    bool invalidNumberEntered = false;

};
