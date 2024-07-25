#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <cstring>
#include <stack>
#include <semaphore.h>

#include "maze.cpp"
#include "audio.cpp"

void* PlayerFruitCollision(void* arg)
{
    MazeAttributes *mazeAttributes = &maze;
    if(maze.P.index==maze.Apple.index && maze.Apple.State)
    {
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,EatFruit,NULL);
        Score+=490;
        maze.Apple.State=false;
    }
    if(maze.P.index==maze.Cherries.index && maze.Cherries.State)
    {
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,EatFruit,NULL);
        Score+=490;
        maze.Cherries.State=false;
    }
    pthread_exit(0);
}

void* PlayerEnergizorCollision(void* arg)
{
    
    MazeAttributes *mazeAttributes = &maze;

    if(maze.P.index==maze.PowerPallet1.index && maze.PowerPallet1.State)
    {
        pthread_mutex_lock(&PlayerPowerCollisionLock);
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,EatFruit,NULL);
        maze.PowerPallet1.State=false;

        maze.Blinky.playerSprit.setTexture(ScaredGhostTexture);
        maze.Inky.playerSprit.setTexture(ScaredGhostTexture);
        maze.Pinky.playerSprit.setTexture(ScaredGhostTexture);
        maze.Clyde.playerSprit.setTexture(ScaredGhostTexture);
        maze.Blinky.Eater=false;
        maze.Clyde.Eater=false;
        maze.Inky.Eater=false;
        maze.Pinky.Eater=false;
        sleep(sf::seconds(10));
        maze.Blinky.playerSprit.setTexture(BlinkyTexture);
        maze.Inky.playerSprit.setTexture(InkyTexture);
        maze.Pinky.playerSprit.setTexture(PinkyTexture);
        maze.Clyde.playerSprit.setTexture(ClydeTexture);
        maze.Blinky.Eater=true;
        maze.Clyde.Eater=true;
        maze.Inky.Eater=true;
        maze.Pinky.Eater=true;
        pthread_mutex_unlock(&PlayerPowerCollisionLock);
    }
    if(maze.P.index==maze.PowerPallet2.index && maze.PowerPallet2.State)
    {
        pthread_mutex_lock(&PlayerPowerCollisionLock);
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,EatFruit,NULL);
        maze.PowerPallet2.State=false;
        maze.Blinky.playerSprit.setTexture(ScaredGhostTexture);
        maze.Inky.playerSprit.setTexture(ScaredGhostTexture);
        maze.Pinky.playerSprit.setTexture(ScaredGhostTexture);
        maze.Clyde.playerSprit.setTexture(ScaredGhostTexture);
        maze.Blinky.Eater=false;
        maze.Clyde.Eater=false;
        maze.Inky.Eater=false;
        maze.Pinky.Eater=false;

        sleep(sf::seconds(10));

        maze.Blinky.playerSprit.setTexture(BlinkyTexture);
        maze.Inky.playerSprit.setTexture(InkyTexture);
        maze.Pinky.playerSprit.setTexture(PinkyTexture);
        maze.Clyde.playerSprit.setTexture(ClydeTexture);
        maze.Blinky.Eater=true;
        maze.Clyde.Eater=true;
        maze.Inky.Eater=true;
        maze.Pinky.Eater=true;
        pthread_mutex_unlock(&PlayerPowerCollisionLock);
    }
    if(maze.P.index==maze.PowerPallet3.index && maze.PowerPallet3.State)
    {
        pthread_mutex_lock(&PlayerPowerCollisionLock);
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,EatFruit,NULL);
        maze.PowerPallet3.State=false;
        maze.Blinky.playerSprit.setTexture(ScaredGhostTexture);
        maze.Inky.playerSprit.setTexture(ScaredGhostTexture);
        maze.Pinky.playerSprit.setTexture(ScaredGhostTexture);
        maze.Clyde.playerSprit.setTexture(ScaredGhostTexture);
        maze.Blinky.Eater=false;
        maze.Clyde.Eater=false;
        maze.Inky.Eater=false;
        maze.Pinky.Eater=false;

        sleep(sf::seconds(10));

        maze.Blinky.playerSprit.setTexture(BlinkyTexture);
        maze.Inky.playerSprit.setTexture(InkyTexture);
        maze.Pinky.playerSprit.setTexture(PinkyTexture);
        maze.Clyde.playerSprit.setTexture(ClydeTexture);
        maze.Blinky.Eater=true;
        maze.Clyde.Eater=true;
        maze.Inky.Eater=true;
        maze.Pinky.Eater=true;
        pthread_mutex_unlock(&PlayerPowerCollisionLock);
    }
    if(maze.P.index==maze.PowerPallet4.index && maze.PowerPallet4.State)
    {
        pthread_mutex_lock(&PlayerPowerCollisionLock);
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,EatFruit,NULL);
        maze.PowerPallet4.State=false;
        maze.Blinky.playerSprit.setTexture(ScaredGhostTexture);
        maze.Inky.playerSprit.setTexture(ScaredGhostTexture);
        maze.Pinky.playerSprit.setTexture(ScaredGhostTexture);
        maze.Clyde.playerSprit.setTexture(ScaredGhostTexture);
        maze.Blinky.Eater=false;
        maze.Clyde.Eater=false;
        maze.Inky.Eater=false;
        maze.Pinky.Eater=false;

        sleep(sf::seconds(10));

        maze.Blinky.playerSprit.setTexture(BlinkyTexture);
        maze.Inky.playerSprit.setTexture(InkyTexture);
        maze.Pinky.playerSprit.setTexture(PinkyTexture);
        maze.Clyde.playerSprit.setTexture(ClydeTexture);
        maze.Blinky.Eater=true;
        maze.Clyde.Eater=true;
        maze.Inky.Eater=true;
        maze.Pinky.Eater=true;
        pthread_mutex_unlock(&PlayerPowerCollisionLock);
    }
    pthread_exit(0);
}

void* PlayerGhostCOllision(void* arg)
{
           
    pthread_mutex_lock(&PlayerGhostCollisionLock);
    MazeAttributes *mazeAttributes = &maze;
    if(maze.P.index==mazeAttributes->Blinky.index && maze.Blinky.Eater)
    {
        cout<<"Player Collision\n";
        Lives--;
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,Death,NULL);

        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        maze.Blinky.SetEntityInfo(213,275,7,9,15);
        maze.Pinky.SetEntityInfo(243,275,8,9,15);
        maze.Pinky.playerSprit.move(-2,-4);
        maze.Inky.SetEntityInfo(303,275,10,9,20);
        maze.Clyde.SetEntityInfo(333,275,11,9,20);
        maze.P.SetEntityInfo(32,32,1,1,10);    
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
    }
    else if(maze.P.index==mazeAttributes->Clyde.index && maze.Clyde.Eater)
    {
        cout<<"Player Collision\n";
        Lives--;
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,Death,NULL);

        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        maze.Blinky.SetEntityInfo(213,275,7,9,15);
        maze.Pinky.SetEntityInfo(243,275,8,9,15);
        maze.Pinky.playerSprit.move(-2,-4);
        maze.Inky.SetEntityInfo(303,275,10,9,20);
        maze.Clyde.SetEntityInfo(333,275,11,9,20);
        maze.P.SetEntityInfo(32,32,1,1,10);    
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
    }
    else if(maze.P.index==mazeAttributes->Inky.index && maze.Inky.Eater)
    {
        cout<<"Player Collision\n";
        Lives--;
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,Death,NULL);

        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        maze.Blinky.SetEntityInfo(213,275,7,9,15);
        maze.Pinky.SetEntityInfo(243,275,8,9,15);
        maze.Pinky.playerSprit.move(-2,-4);
        maze.Inky.SetEntityInfo(303,275,10,9,20);
        maze.Clyde.SetEntityInfo(333,275,11,9,20);
        maze.P.SetEntityInfo(32,32,1,1,10);    
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
    }
    else if(maze.P.index==mazeAttributes->Pinky.index && maze.Pinky.Eater)
    {
        cout<<"Player Collision\n";
        Lives--;
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,Death,NULL);

        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        maze.Blinky.SetEntityInfo(213,275,7,9,15);
        maze.Pinky.SetEntityInfo(243,275,8,9,15);
        maze.Pinky.playerSprit.move(-2,-4);
        maze.Inky.SetEntityInfo(303,275,10,9,20);
        maze.Clyde.SetEntityInfo(333,275,11,9,20);
        maze.P.SetEntityInfo(32,32,1,1,10);    
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
    }
    
    else if((maze.P.index==mazeAttributes->Blinky.index && maze.Blinky.Eater==false))
    {
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,GhostDeath,NULL);
        Score+=100;

        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        maze.Blinky.SetEntityInfo(213,275,7,9,15);
        maze.Blinky.playerSprit.setTexture(BlinkyTexture);
        maze.Blinky.InsideHouse=true;
        maze.Blinky.Eater=true;
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
    }
    else if(maze.P.index==mazeAttributes->Clyde.index && maze.Clyde.Eater==false)
    {
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,GhostDeath,NULL);
        Score+=100;

        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        maze.Clyde.SetEntityInfo(333,275,11,9,20);
        maze.Clyde.playerSprit.setTexture(ClydeTexture);
        maze.Clyde.InsideHouse=true;      
        maze.Clyde.Eater=1;  
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);

    }
    else if((maze.P.index==mazeAttributes->Inky.index && maze.Inky.Eater==false))
    {
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,GhostDeath,NULL);
        Score+=100;

        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        maze.Inky.SetEntityInfo(303,275,10,9,20);
        maze.Inky.InsideHouse=true;
        maze.Inky.playerSprit.setTexture(InkyTexture);
        maze.Inky.Eater=1;
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);

    }
    else if(maze.P.index==mazeAttributes->Pinky.index && maze.Pinky.Eater==false)
    {
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,GhostDeath,NULL);
        Score+=100;

        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        sem_wait(&GhostPause);
        maze.Pinky.SetEntityInfo(243,275,8,9,15);
        maze.Pinky.playerSprit.setTexture(PinkyTexture);
        maze.Pinky.InsideHouse=true;
        maze.Pinky.playerSprit.move(-2,-4);
        maze.Pinky.Eater=1;
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);
        sem_post(&GhostPause);

    }
    pthread_mutex_unlock(&PlayerGhostCollisionLock);
    

    pthread_exit(0);

}

void* BLinkyHouseKeyGetter(void* arg)
{
    MazeAttributes *mazeAttributes = &maze;
    Entity &pacman = mazeAttributes->Blinky;

    pacman.InsideHouse=false;
    while(pacman.index.x!=9 && pacman.index.y!=9);

    sem_wait(&GhostHouseKeyLock);
    //cout<<"Got Key"<<endl;
    sleep(sf::seconds(5));

    sem_wait(&GhostHousePermitLock);
    //cout<<"Got Permit"<<endl;
    sem_post(&GhostHouseKeyLock);
    //cout<<"Released Key"<<endl;

    while(pacman.index.x!=9 && pacman.index.y!=9);
    pacman.playerSprit.move(0,-60);
    pacman.index.y=pacman.index.y-2;

    sleep(sf::seconds(10));
    sem_post(&GhostHousePermitLock);
    //cout<<"Released Permit"<<endl;

    pthread_exit(0);
}

void* PinkyHouseKeyGetter(void* arg)
{
    MazeAttributes *mazeAttributes = &maze;
    Entity &pacman = mazeAttributes->Pinky;

    pacman.InsideHouse=false;
    while(pacman.index.x!=9 && pacman.index.y!=9);

    sem_wait(&GhostHouseKeyLock);
    //cout<<"Got Key"<<endl;
    sleep(sf::seconds(5));

    sem_wait(&GhostHousePermitLock);
    //cout<<"Got Permit"<<endl;
    sem_post(&GhostHouseKeyLock);
    //cout<<"Released Key"<<endl;

    while(pacman.index.x!=9 && pacman.index.y!=9);
    pacman.playerSprit.move(0,-60);
    pacman.index.y=pacman.index.y-2;

    sleep(sf::seconds(10));
    sem_post(&GhostHousePermitLock);
    //cout<<"Released Permit"<<endl;

    pthread_exit(0);
}

void* InkyHouseKeyGetter(void* arg)
{
    MazeAttributes *mazeAttributes = &maze;
    Entity &pacman = mazeAttributes->Inky;

    pacman.InsideHouse=false;
    while(pacman.index.x!=9 && pacman.index.y!=9);

    sem_wait(&GhostHouseKeyLock);
    //cout<<"Got Key"<<endl;
    sleep(sf::seconds(5));

    sem_wait(&GhostHousePermitLock);
    //cout<<"Got Permit"<<endl;
    sem_post(&GhostHouseKeyLock);
    //cout<<"Released Key"<<endl;

    while(pacman.index.x!=9 && pacman.index.y!=9);
    pacman.playerSprit.move(0,-60);
    pacman.index.y=pacman.index.y-2;

    sleep(sf::seconds(10));
    sem_post(&GhostHousePermitLock);
    //cout<<"Released Permit"<<endl;

    pthread_exit(0);
}

void* ClydeHouseKeyGetter(void* arg)
{
    MazeAttributes *mazeAttributes = &maze;
    Entity &pacman = mazeAttributes->Clyde;

    pacman.InsideHouse=false;
    while(pacman.index.x!=9 && pacman.index.y!=9);

    sem_wait(&GhostHouseKeyLock);
    //cout<<"Got Key"<<endl;
    sleep(sf::seconds(5));

    sem_wait(&GhostHousePermitLock);
    //cout<<"Got Permit"<<endl;
    sem_post(&GhostHouseKeyLock);
    //cout<<"Released Key"<<endl;

    while(pacman.index.x!=9 && pacman.index.y!=9);
    pacman.playerSprit.move(0,-60);
    pacman.index.y=pacman.index.y-2;

    sleep(sf::seconds(10));
    sem_post(&GhostHousePermitLock);
    //cout<<"Released Permit"<<endl;

    pthread_exit(0);
}

void GhostSpeedBostSetter(Entity &temp)
{
    Entity &pacman = temp;
    int old = temp.speed;
    temp.speed =7;
    sleep(sf::seconds(15));
    temp.speed = old;
}

//  Ghost Speed Bost Generator
void *RandomGhostSpeedSelector(void *arg)
{
    MazeAttributes *mazeAttributes = &maze;
    sem_wait(&GhostSpeedBost);

    int r1 = rand() % 3;

    if (r1 == 0)
        GhostSpeedBostSetter(maze.Blinky);
    if (r1 == 1)
        GhostSpeedBostSetter(maze.Clyde);
    if (r1 == 2)
        GhostSpeedBostSetter(maze.Inky);
    if (r1 == 3)
        GhostSpeedBostSetter(maze.Pinky);

    sleep(sf::seconds(45));
    sem_post(&GhostSpeedBost);

    pthread_exit(0);
}

//Ghost Movement Randomizor
void GhostMovementRandom(Entity &temp)
{
    Entity &pacman = temp;
    MazeAttributes *mazeAttributes = &maze;

    if (pacman.Direction == 1 || pacman.Direction==3)
    {
        if (mazeAttributes->Maze[pacman.index.x][pacman.index.y - 1].wall == false || mazeAttributes->Maze[pacman.index.x][pacman.index.y + 1].wall == false || mazeAttributes->Maze[pacman.index.x][pacman.index.y - 1].wall == 2 || mazeAttributes->Maze[pacman.index.x][pacman.index.y + 1].wall == 2)
        {
            if (rand() % 2 == 0)
                pacman.Direction = 0;
            else
                pacman.Direction = 2;
        }
    }
    else if (pacman.Direction == 2 || pacman.Direction==0)
    {
        if (mazeAttributes->Maze[pacman.index.x + 1][pacman.index.y].wall == false || mazeAttributes->Maze[pacman.index.x + 1][pacman.index.y].wall == 2 || mazeAttributes->Maze[pacman.index.x - 1][pacman.index.y].wall == false ||mazeAttributes->Maze[pacman.index.x - 1][pacman.index.y].wall == 2)
        {
        
            if (rand() % 2 == 0)
                pacman.Direction = 1;
            else
                pacman.Direction = 3;
        }
    }

    if (pacman.Direction == 1 && mazeAttributes->Maze[pacman.index.x + 1][pacman.index.y].wall==1)
        pacman.Direction = 3;
    else if (pacman.Direction == 3 && mazeAttributes->Maze[pacman.index.x - 1][pacman.index.y].wall==1)
        pacman.Direction = 1;
    else if (pacman.Direction == 0 && mazeAttributes->Maze[pacman.index.x][pacman.index.y - 1].wall==1)
        pacman.Direction = 2;
    else if (pacman.Direction == 2 && mazeAttributes->Maze[pacman.index.x][pacman.index.y + 1].wall==1)
        pacman.Direction = 0;
}

void *ClydeMovement(void *arg)
{
    pthread_mutex_lock(&ClydeMovementLock);
    sleep(sf::milliseconds(5));
    sem_wait(&GhostPause);
    MazeAttributes *mazeAttributes = &maze;
    Entity &pacman = mazeAttributes->Clyde;

    if (pacman.Direction == 1 && (mazeAttributes->Maze[pacman.index.x + 1][pacman.index.y].wall == false || mazeAttributes->Maze[pacman.index.x + 1][pacman.index.y].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(1, 0);
        } while (n < 30);
        pacman.index.x++;
    }
    if (pacman.Direction == 3 && (mazeAttributes->Maze[pacman.index.x - 1][pacman.index.y].wall == false || mazeAttributes->Maze[pacman.index.x - 1][pacman.index.y].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(-1, 0);
        } while (n < 30);
        pacman.index.x--;
    }
    if (pacman.Direction == 0 && (mazeAttributes->Maze[pacman.index.x][pacman.index.y - 1].wall == false || mazeAttributes->Maze[pacman.index.x][pacman.index.y - 1].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(0, -1);
        } while (n < 30);
        pacman.index.y--;
    }
    if (pacman.Direction == 2 && (mazeAttributes->Maze[pacman.index.x][pacman.index.y + 1].wall == false || mazeAttributes->Maze[pacman.index.x][pacman.index.y + 1].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(0, 1);
        } while (n < 30);
        pacman.index.y++;
    }

    if(pacman.InsideHouse==true)
    {
        cout<<"Went for Key"<<endl;
        pthread_t ThreadForGettigOut;
        pthread_create(&ThreadForGettigOut, nullptr, ClydeHouseKeyGetter, NULL);
    }

    GhostMovementRandom(pacman);

    pthread_mutex_unlock(&ClydeMovementLock);
    sem_post(&GhostPause);
    pthread_exit(0);
}

void *InkyMovement(void *arg)
{
    pthread_mutex_lock(&InkyMovementLock);
    sleep(sf::milliseconds(5));
    sem_wait(&GhostPause);
    MazeAttributes *mazeAttributes = &maze;
    Entity &pacman = mazeAttributes->Inky;

    if (pacman.Direction == 1 && (mazeAttributes->Maze[pacman.index.x + 1][pacman.index.y].wall == false || mazeAttributes->Maze[pacman.index.x + 1][pacman.index.y].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(1, 0);
        } while (n < 30);
        pacman.index.x++;
    }
    if (pacman.Direction == 3 && (mazeAttributes->Maze[pacman.index.x - 1][pacman.index.y].wall == false || mazeAttributes->Maze[pacman.index.x - 1][pacman.index.y].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(-1, 0);
        } while (n < 30);
        pacman.index.x--;
    }
    if (pacman.Direction == 0 && (mazeAttributes->Maze[pacman.index.x][pacman.index.y - 1].wall == false || mazeAttributes->Maze[pacman.index.x][pacman.index.y - 1].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(0, -1);
        } while (n < 30);
        pacman.index.y--;
    }
    if (pacman.Direction == 2 && (mazeAttributes->Maze[pacman.index.x][pacman.index.y + 1].wall == false || mazeAttributes->Maze[pacman.index.x][pacman.index.y + 1].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(0, 1);
        } while (n < 30);
        pacman.index.y++;
    }

    if(pacman.InsideHouse==true)
    {
        cout<<"Went for Key"<<endl;
        pthread_t ThreadForGettigOut;
        pthread_create(&ThreadForGettigOut, nullptr, InkyHouseKeyGetter, NULL);
    }

    GhostMovementRandom(pacman);

    sem_post(&GhostPause);
    pthread_mutex_unlock(&InkyMovementLock);
    pthread_exit(0);
}

void *PinkyMovement(void *arg)
{
    pthread_mutex_lock(&PinkyMovementLock);
    sleep(sf::milliseconds(5));
    sem_wait(&GhostPause);
    MazeAttributes *mazeAttributes = &maze;
    Entity &pacman = mazeAttributes->Pinky;
    if (pacman.Direction == 1 && (mazeAttributes->Maze[pacman.index.x + 1][pacman.index.y].wall == false || mazeAttributes->Maze[pacman.index.x + 1][pacman.index.y].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(1, 0);
        } while (n < 30);
        pacman.index.x++;
    }
    if (pacman.Direction == 3 && (mazeAttributes->Maze[pacman.index.x - 1][pacman.index.y].wall == false || mazeAttributes->Maze[pacman.index.x - 1][pacman.index.y].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(-1, 0);
        } while (n < 30);
        pacman.index.x--;
    }
    if (pacman.Direction == 0 && (mazeAttributes->Maze[pacman.index.x][pacman.index.y - 1].wall == false || mazeAttributes->Maze[pacman.index.x][pacman.index.y - 1].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(0, -1);
        } while (n < 30);
        pacman.index.y--;
    }
    if (pacman.Direction == 2 && (mazeAttributes->Maze[pacman.index.x][pacman.index.y + 1].wall == false || mazeAttributes->Maze[pacman.index.x][pacman.index.y + 1].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(0, 1);
        } while (n < 30);
        pacman.index.y++;
    }
    
    if(pacman.InsideHouse==true)
    {
        cout<<"Went for Key"<<endl;
        pthread_t ThreadForGettigOut;
        pthread_create(&ThreadForGettigOut, nullptr, PinkyHouseKeyGetter, NULL);
    }

    GhostMovementRandom(pacman);

    pthread_mutex_unlock(&PinkyMovementLock);
    sem_post(&GhostPause);
    pthread_exit(0);
}

void *BlinkyMovemnet(void *arg)
{
    pthread_mutex_lock(&BlinkyMovementLock);
    sleep(sf::milliseconds(5));
    sem_wait(&GhostPause);
    MazeAttributes *mazeAttributes = &maze;
    Entity &pacman = mazeAttributes->Blinky;
    if (pacman.Direction == 1 && (mazeAttributes->Maze[pacman.index.x + 1][pacman.index.y].wall == false || mazeAttributes->Maze[pacman.index.x + 1][pacman.index.y].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(1, 0);
        } while (n < 30);
        pacman.index.x++;
    }
    if (pacman.Direction == 3 && (mazeAttributes->Maze[pacman.index.x - 1][pacman.index.y].wall == false || mazeAttributes->Maze[pacman.index.x - 1][pacman.index.y].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(-1, 0);
        } while (n < 30);
        pacman.index.x--;
    }
    if (pacman.Direction == 0 && (mazeAttributes->Maze[pacman.index.x][pacman.index.y - 1].wall == false || mazeAttributes->Maze[pacman.index.x][pacman.index.y - 1].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(0, -1);
        } while (n < 30);
        pacman.index.y--;
    }
    if (pacman.Direction == 2 && (mazeAttributes->Maze[pacman.index.x][pacman.index.y + 1].wall == false || mazeAttributes->Maze[pacman.index.x][pacman.index.y + 1].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(pacman.speed));
            pacman.playerSprit.move(0, 1);
        } while (n < 30);
        pacman.index.y++;
    }
    
    if(pacman.InsideHouse==true)
    {
        cout<<"Went for Key"<<endl;
        pthread_t ThreadForGettigOut;
        pthread_create(&ThreadForGettigOut, nullptr, BLinkyHouseKeyGetter, NULL);
    }
        
    GhostMovementRandom(pacman);

    pthread_mutex_unlock(&BlinkyMovementLock);
    sem_post(&GhostPause);
    pthread_exit(0);
}

//  Player Movement With Mutex
void *PacmanMovement(void *arg)
{
    pthread_mutex_lock(&PlayerMovementLock);
    sleep(sf::milliseconds(5));
    sem_wait(&GhostPause);
    MazeAttributes *mazeAttributes = &maze;
    Entity &pacman = mazeAttributes->P;


    if (pacman.Direction == 1 && (mazeAttributes->Maze[pacman.index.x + 1][pacman.index.y].wall == 2 || mazeAttributes->Maze[pacman.index.x + 1][pacman.index.y].wall == false))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(5));
            pacman.playerSprit.move(1, 0);

        } while (n < 30);
        pacman.index.x++;
    }
    if (pacman.Direction == 3 && (mazeAttributes->Maze[pacman.index.x - 1][pacman.index.y].wall == false || mazeAttributes->Maze[pacman.index.x - 1][pacman.index.y].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(5));
            pacman.playerSprit.move(-1, 0);
        } while (n < 30);
        pacman.index.x--;
    }
    if (pacman.Direction == 0 && (mazeAttributes->Maze[pacman.index.x][pacman.index.y - 1].wall == false || mazeAttributes->Maze[pacman.index.x][pacman.index.y - 1].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(5));
            pacman.playerSprit.move(0, -1);
        } while (n < 30);
        pacman.index.y--;
    }
    if (pacman.Direction == 2 && (mazeAttributes->Maze[pacman.index.x][pacman.index.y + 1].wall == false || mazeAttributes->Maze[pacman.index.x][pacman.index.y + 1].wall == 2))
    {
        int n = 0;
        do
        {
            n++;
            sleep(sf::milliseconds(5));
            pacman.playerSprit.move(0, 1);
        } while (n < 30);
        pacman.index.y++;
    }
    if (mazeAttributes->Maze[pacman.index.x][pacman.index.y].wall == false)
    {
        mazeAttributes->Maze[pacman.index.x][pacman.index.y].wall = 2;
        Score += 10;
        pthread_t chompthread;
        pthread_create(&chompthread,nullptr,Chomp,NULL);
    }
    //cout<<pacman.index.x<<" "<<pacman.index.y<<endl;
    pthread_mutex_unlock(&PlayerMovementLock);
    sem_post(&GhostPause);
    pthread_exit(0);
}

//  Player Movement input;
void Movement()
{
    /*
     PacmanTextureLeft.loadFromFile("assets/pacman_left.png");
    PacmanTextureUp.loadFromFile("assets/pacman_up.png");
    PacmanTextureDown.loadFromFile("assets/pacman_down.png");
    */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        maze.P.Direction = 0;
        maze.P.playerSprit.setTexture(PacmanTextureUp);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        maze.P.Direction = 3;
        maze.P.playerSprit.setTexture(PacmanTextureLeft);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        maze.P.Direction = 2;
        maze.P.playerSprit.setTexture(PacmanTextureDown);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        maze.P.Direction = 1;
        maze.P.playerSprit.setTexture(PacmanTextureRight);
    }
        
}