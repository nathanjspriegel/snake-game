#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

const int cellSize = 20;
const int gridWidth = 45;
const int gridHeight = 45;
const int windowLength = gridWidth * cellSize;
const int windowHeight = gridHeight * cellSize;

int main()
{
    int currentColumn = 22;
    int currentRow = 22;
    float x = static_cast<float>(currentColumn * cellSize);
    float y = static_cast<float>(currentRow * cellSize);

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
        }

        window.clear();
        snake.setPosition({x, y});
        window.draw(snake);
        window.display();
    }

    return 0;
}
