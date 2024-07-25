#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <cstring>
#include <stack>
#include <semaphore.h>

//#include "maze.cpp"
#include "movement.cpp"

using namespace std;
using namespace sf;



int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Maze Display");
    window.setFramerateLimit(60);
    srand(time(NULL));

    Text ScoreText;
    Text ScoreTextText;
    Text LivesTest;
    Text LivesTextText;
    ScoreText.setFont(font);
    ScoreTextText.setFont(font);
    LivesTest.setFont(font);
    LivesTextText.setFont(font);

    ScoreText.setCharacterSize(32);
    LivesTest.setCharacterSize(32);
    ScoreTextText.setCharacterSize(32);
    LivesTextText.setCharacterSize(32);

    ScoreText.setPosition(700,200);
    ScoreTextText.setPosition(600,200);
    LivesTest.setPosition(700,300);
    LivesTextText.setPosition(600,300);

    ScoreTextText.setString("Score: ");
    LivesTextText.setString("Lives: ");

    ScoreText.setFillColor(sf::Color::White);
    ScoreTextText.setFillColor(sf::Color::White);
    LivesTest.setFillColor(sf::Color::White);
    LivesTextText.setFillColor(sf::Color::White);

    maze.InitializeMaze(19, 26);

    sem_init(&GhostSpeedBost, 0, 2);
    sem_init(&GhostHouseKeyLock, 0, 1);
    sem_init(&GhostHousePermitLock, 0, 1);
    sem_init(&GhostPause,0,5);

    float moveTimer = 0;
    float ghostmovetimer = 0;

    //pthread_t runningGameThread;

    while (window.isOpen() && Lives>0)
    {

        moveTimer += Timer.getElapsedTime().asMilliseconds();
        ghostmovetimer += Timer.getElapsedTime().asMilliseconds();
        Timer.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        Movement();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            window.close();
        }

        

        pthread_t PlayerMovementThread;

        pthread_t GhostMovementThreadr1;
        pthread_t GhostMovementThreadr2;

        pthread_t BlinkyMovementThread;
        pthread_t ClydeMovementThread;
        pthread_t PinkyMovementThread;
        pthread_t InkyMovementThread;
        pthread_t GhostPlayerCollisionThread;
        pthread_t PlayerPowerCollisionThread;
        pthread_t PlayerFruitsCollisionThread;
        window.clear(sf::Color::Black);


    
        pthread_create(&PlayerMovementThread, nullptr, PacmanMovement, NULL);
        pthread_create(&BlinkyMovementThread, nullptr, BlinkyMovemnet, NULL);
        pthread_create(&PinkyMovementThread, nullptr, PinkyMovement, NULL);
        pthread_create(&InkyMovementThread, nullptr, InkyMovement, NULL);
        pthread_create(&ClydeMovementThread, nullptr, ClydeMovement, NULL);
        pthread_create(&GhostMovementThreadr1, nullptr, RandomGhostSpeedSelector, NULL);
        pthread_create(&GhostMovementThreadr2, nullptr, RandomGhostSpeedSelector, NULL);
        pthread_create(&GhostPlayerCollisionThread,nullptr,PlayerGhostCOllision,NULL);
        pthread_create(&PlayerFruitsCollisionThread,nullptr,PlayerFruitCollision,NULL);
        pthread_create(&PlayerPowerCollisionThread,nullptr,PlayerEnergizorCollision,NULL);
        
        for (int i = 0; i < maze.row; ++i)
        {
            for (int j = 0; j < maze.col; ++j)
            {
                RectangleShape *rect = maze.Maze[i][j].cell;
                rect->setPosition(Vector2f(maze.Maze[i][j].coordinates.x, maze.Maze[i][j].coordinates.y));

                if (maze.Maze[i][j].wall==1)
                {
                    rect->setFillColor(Color::Cyan);
                    maze.Maze[i][j].cellSprite.setPosition(Vector2f(maze.Maze[i][j].coordinates.x, maze.Maze[i][j].coordinates.y));
                    window.draw(maze.Maze[i][j].cellSprite);
                }
                else if (maze.Maze[i][j].wall == false)
                {
                    rect->setFillColor(Color::White);
                    rect->setSize(Vector2f(4, 4));
                    rect->setPosition(rect->getPosition().x + 13, rect->getPosition().y + 13);
                }
                else if (maze.Maze[i][j].wall == 2)
                {
                    rect->setFillColor(Color::Black);
                }

                if (j == 9 && i > 6 && i < 12)
                {
                   
                }
                else
                {
                    window.draw(*rect);
                    window.draw(maze.Maze[i][j].cellSprite);
                }
            }
        }
        if(maze.Cherries.State)
            window.draw(maze.Cherries.playerSprit);
        if(maze.Apple.State)
            window.draw(maze.Apple.playerSprit);
        if(maze.PowerPallet1.State)
            window.draw(maze.PowerPallet1.playerSprit);
        if(maze.PowerPallet2.State)
            window.draw(maze.PowerPallet2.playerSprit);
        if(maze.PowerPallet3.State)
            window.draw(maze.PowerPallet3.playerSprit);
        if(maze.PowerPallet4.State)
            window.draw(maze.PowerPallet4.playerSprit);

        window.draw(maze.Inky.playerSprit);
        window.draw(maze.Clyde.playerSprit);
        window.draw(maze.Pinky.playerSprit);
        window.draw(maze.Blinky.playerSprit);

        window.draw(maze.P.playerSprit);

        ScoreText.setString(to_string(Score));
        LivesTest.setString(to_string(Lives));
        window.draw(ScoreText);
        window.draw(ScoreTextText);
        window.draw(LivesTest);
        window.draw(LivesTextText);

        window.display();
    }

    return 0;
}
