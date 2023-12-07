#include "GameState.h"
#include <iostream>

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states)
    : State(window, states)
{
    // Set the background color of the window
    this->window->clear(sf::Color(50, 50, 50)); // Dark gray

    int mapW = 9;
    int mapH = 9;

    this->window->create(sf::VideoMode(600, 600), "Sudoku");

    sf::Font font;
    if (!font.loadFromFile("fonts/Inria_Serif/InriaSerif-Bold.ttf")) {
        std::cout << "Error loading font file.\n";
    }

    sf::Text tileText;
    tileText.setFont(font);
    tileText.setCharacterSize(30);
    tileText.setFillColor(sf::Color::White);

    int sudoku[9][9] = {};
    int selectedTileX = 0;
    int selectedTileY = 0;
    int selectedTileValue = 0;

    sf::String currentInput;
    bool invalidNumberEntered = false;

    while (this->window->isOpen()) {
        sf::Event event;
        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->window->close();
            }
            else if (event.type == sf::Event::TextEntered) {
                handleInput(event.text, currentInput, selectedTileValue, sudoku, selectedTileX, selectedTileY);
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                // Determine the selected tile based on mouse coordinates
                selectedTileX = event.mouseButton.x / 50;
                selectedTileY = event.mouseButton.y / 50;
                currentInput.clear(); // Clear the current input when a new tile is selected
            }
        }

        // Clear the window with the background color
        this->window->clear(sf::Color(50, 50, 50)); // Dark gray

        // Draw Sudoku grid with the selected tile
        drawGrid(*this->window, mapW, mapH, 50.f, selectedTileX, selectedTileY);

        // Display Sudoku grid
        for (int y = 0; y < mapH; y++) {
            for (int x = 0; x < mapW; x++) {
                tileText.setString((sudoku[y][x] != 0 ? std::to_string(sudoku[y][x]) : ""));
                tileText.setPosition(x * 50.f, y * 50.f);
                this->window->draw(tileText);
            }
        }

        this->window->display();
    }
}

GameState::~GameState()
{
}

void GameState::endState()
{
    std::cout << "Ending GameState!" << std::endl;
}

void GameState::updateInput(const float& dt)
{
    this->checkForQuit();
}

void GameState::update(const float& dt)
{
    this->updateInput(dt);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        std::cout << "A" << std::endl;
}

void GameState::render(sf::RenderTarget* target)
{
    if (!target) {
        target = this->window;
    }

    target->draw(this->background);
}

bool GameState::isValidSudoku(const int sudoku[9][9], int row, int col, int num)
{
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == num || sudoku[i][col] == num) {
            std::cout << "Invalid number! Number already exists in the same row or column" << std::endl;
            return false;
        }
    }

    // Check the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (sudoku[i + startRow][j + startCol] == num) {
                std::cout << "Invalid number! Number already exists in the 3x3 subgrid.\n";
                return false;
            }
        }
    }

    return true;
}

bool GameState::isNumberValid(const int sudoku[9][9], int row, int col, int num)
{
    return isValidSudoku(sudoku, row, col, num);
}

void GameState::drawGrid(sf::RenderWindow& window, int mapW, int mapH, float tileSize, int selectedTileX, int selectedTileY)
{
    sf::Color gridColor(255, 255, 255, 100);

    for (int y = 0; y < mapH; y++) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(0, (y + 1) * tileSize)),
            sf::Vertex(sf::Vector2f(mapW * tileSize, (y + 1) * tileSize))
        };
        line[0].color = gridColor;
        line[1].color = gridColor;
        window.draw(line, 2, sf::Lines);
    }

    for (int x = 0; x <= mapW; x++) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(x * tileSize, 0)),
            sf::Vertex(sf::Vector2f(x * tileSize, mapH * tileSize))
        };
        line[0].color = gridColor;
        line[1].color = gridColor;
        window.draw(line, 2, sf::Lines);
    }

    // Draw a rectangle around the selected tile
    sf::RectangleShape selectedTileRect(sf::Vector2f(tileSize, tileSize));
    selectedTileRect.setFillColor(sf::Color::Transparent);
    selectedTileRect.setOutlineColor(sf::Color::Magenta);
    selectedTileRect.setOutlineThickness(2.f);
    selectedTileRect.setPosition(selectedTileX * tileSize, selectedTileY * tileSize);
    window.draw(selectedTileRect);
}

void GameState::handleInput(sf::Event::TextEvent textEvent, sf::String& currentInput, int& selectedTileValue, int sudoku[9][9], int selectedTileX, int selectedTileY)
{
    char enteredChar = static_cast<char>(textEvent.unicode);

    if (std::isdigit(enteredChar) && currentInput.getSize() < 1) {
        int digit = enteredChar - '0';
        // Adjust indices to zero-based
        if (digit >= 1 && digit <= 9 && isNumberValid(sudoku, selectedTileY, selectedTileX, digit)) {
            // Adjust indices to zero-based
            sudoku[selectedTileY][selectedTileX] = digit;
            currentInput += enteredChar;
            selectedTileValue = digit;
        }
        else {
            std::cout << "Invalid input! Please enter a number from 1 to 9.\n";
        }
    }
    else {
        // Display an error message for invalid input
        std::cout << "Invalid input! Please enter a number from 1 to 9.\n";
    }
}
