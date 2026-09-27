#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

void movement(int &currentColumn, int &currentRow, std::string &direction);
bool hitWall(int &column, int &row);

const int cellSize = 20;
const int gridWidth = 45;
const int gridHeight = 45;
const int windowLength = gridWidth * cellSize;
const int windowHeight = gridHeight * cellSize;

int main()
{
    bool gameOver = false;

    int currentColumn = 22;
    int currentRow = 22;

    const float moveInterval = 0.1f;

    std::string direction = "right";
    std::string lastDirection = "right";

    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(windowLength, windowHeight), "Snake window");

    sf::RectangleShape snake(sf::Vector2f(cellSize, cellSize));

    snake.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up && lastDirection != "down")
                    direction = "up";
                if (event.key.code == sf::Keyboard::Down && lastDirection != "up")
                    direction = "down";
                if (event.key.code == sf::Keyboard::Right && lastDirection != "left")
                    direction = "right";
                if (event.key.code == sf::Keyboard::Left && lastDirection != "right")
                    direction = "left";
            }
        }

        if (clock.getElapsedTime().asSeconds() >= moveInterval && !gameOver)
        {
            movement(currentColumn, currentRow, direction);
            if (hitWall(currentColumn, currentRow))
                gameOver = true;
            lastDirection = direction;
            clock.restart();
        }

        window.clear();
        float x = static_cast<float>(currentColumn * cellSize);
        float y = static_cast<float>(currentRow * cellSize);
        snake.setPosition({x, y});
        window.draw(snake);
        window.display();
    }

    return 0;
}

void movement(int &column, int &row, std::string &direction)
{
    // Row 0 is top of window
    if (direction == "up")
        row -= 1;
    else if (direction == "down")
        row += 1;
    else if (direction == "left")
        column -= 1;
    else if (direction == "right")
        column += 1;
}

bool hitWall(int &column, int &row)
{
    return (column < 0 || column >= gridWidth || row < 0 || row >= gridHeight);
}