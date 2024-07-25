#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/Audio.hpp>
#include <cstring>
#include <semaphore.h>

using namespace std;
using namespace sf;

Texture PacmanTextureRight;
Texture PacmanTextureLeft;
Texture PacmanTextureUp;
Texture PacmanTextureDown;
Texture InkyTexture;
Texture PinkyTexture;
Texture BlinkyTexture;
Texture ClydeTexture;
Texture WallTexture;
Texture ScaredGhostTexture;
Texture CherriesTexture;
Texture AppleTexture;
Texture EnergizerTexture;

Font font;

void TextureLoaderFunction()
{
    PacmanTextureRight.loadFromFile("assets/pacman_right.png");
    PacmanTextureLeft.loadFromFile("assets/pacman_left.png");
    PacmanTextureUp.loadFromFile("assets/pacman_up.png");
    PacmanTextureDown.loadFromFile("assets/pacman_down.png");
    InkyTexture.loadFromFile("assets/inky.png");
    PinkyTexture.loadFromFile("assets/pinky.png");
    BlinkyTexture.loadFromFile("assets/blinky.png");
    ClydeTexture.loadFromFile("assets/clyde.png");
    WallTexture.loadFromFile("assets/greystone.png");
    ScaredGhostTexture.loadFromFile("assets/frightened.png");
    CherriesTexture.loadFromFile("assets/cherries.png");
    AppleTexture.loadFromFile("assets/apple.png");
    EnergizerTexture.loadFromFile("assets/energizer.png");

    font.loadFromFile("assets/cairo.ttf");
}

class Item
{
public:

    Sprite playerSprit;
    Vector2i index;
    bool State;
    Item()
    {
        State=true;
    }
    void SetItemInfo(int x,int y,int t)
    {
        playerSprit.setPosition(x,y);

        index.x=x/30;
        index.y=y/30;

        if(t==0)
        {
            playerSprit.setTexture(CherriesTexture);
        }
        else if(t==1)
        {
            playerSprit.setTexture(AppleTexture);
            playerSprit.setScale(0.85,0.85);
        }
        else if(t==2)
        {
            playerSprit.setTexture(EnergizerTexture);
            playerSprit.setScale(0.85,0.85);
            playerSprit.move(0,4);
        }
    }

};

class Entity
{
public:
    CircleShape player;
    Sprite playerSprit;
    Vector2i index;
    int Direction;
    bool Eater;
    float speed;
    bool InsideHouse;
    Entity()
    {
        player.setRadius(10);
        player.setPosition(35,35);
        playerSprit.setPosition(32,32);
        playerSprit.setScale(0.8,0.8);
        player.setFillColor(Color::Yellow);
        index.x=1;
        index.y=1;
        Direction=1;
        Eater=false;
        speed=10;
        InsideHouse=true;
    }
    void SetEntityInfo(int x,int y,int x1,int y1,int s)
    {
        player.setPosition(x,y);
        playerSprit.setPosition(x,y);
        index.x=x1;
        index.y=y1;
        speed=s;
        InsideHouse=true;
    }
};

struct Node
{
    RectangleShape* cell;
    Sprite cellSprite;
    Vector2i coordinates;
    int wall;
    Node() : cell(nullptr), wall(false) 
    {
        cellSprite.setTexture(WallTexture);
    }
};

class MazeAttributes
{
public:
    Node** Maze;
    int row;
    int col;
    Entity P;

    Item Cherries;
    Item Apple;

    Item PowerPallet1;
    Item PowerPallet2;
    Item PowerPallet3;
    Item PowerPallet4;

    Entity Blinky;   //  red
    Entity Pinky;    //  pink
    Entity Inky;     //  cyan
    Entity Clyde;    //  orange

    MazeAttributes()  {}

    void InitializeMaze(int r,int c)
    {
        TextureLoaderFunction();
        P.InsideHouse=false;
        row=r;
        col=c;
        Maze = new Node*[row];
        for(int n=0;n<row;n++)
            Maze[n] = new Node[col];

        Blinky.SetEntityInfo(213,275,7,9,15);
        Pinky.SetEntityInfo(243,275,8,9,15);
        Inky.SetEntityInfo(303,275,10,9,20);
        Clyde.SetEntityInfo(333,275,11,9,20);

        Cherries.SetItemInfo(270,330,0);
        Apple.SetItemInfo(270,720,1);
        PowerPallet1.SetItemInfo(60,600,2);
        PowerPallet2.SetItemInfo(480,600,2);
        PowerPallet3.SetItemInfo(150,210,2);
        PowerPallet4.SetItemInfo(420,210,2);

        Blinky.player.setFillColor(sf::Color::Red);
        Pinky.player.setFillColor(sf::Color::Magenta);
        Inky.player.setFillColor(sf::Color::Cyan);
        Clyde.player.setFillColor(sf::Color::Green);

        Blinky.playerSprit.setTexture(BlinkyTexture);
        Blinky.playerSprit.setScale(0.7,0.7);
        Pinky.playerSprit.setTexture(PinkyTexture);
        Pinky.playerSprit.setScale(0.9,0.9);
        Pinky.playerSprit.move(-2,-4);
        Inky.playerSprit.setTexture(InkyTexture);
        Inky.playerSprit.setScale(0.7,0.7);
        Clyde.playerSprit.setTexture(ClydeTexture);
        Clyde.playerSprit.setScale(0.7,0.7);

        P.playerSprit.setTexture(PacmanTextureRight);

        

        for(int n=0;n<row;n++)
        {
            for(int m=0;m<col;m++)
            {
                if(m==0 || m==col-1 || n==0 || n==row-1)
                {

                    Maze[n][m].wall=1;
                }
                else if(m==1)
                {

                    if(n==7 || n==11)
                        Maze[n][m].wall=1;
                }
                else if(m==2)
                {

                    if(n==3 || n==2 || n==5 ||n==7 || n==9 ||n==11 || n==13 ||n==15 || n==16)
                       Maze[n][m].wall=1;
                }
                else if(m==3)
                {
                    if(n==5 || n==9 || n==13)
                        Maze[n][m].wall=1;
                }
                else if(m==4)
                {
                    if(n==3 || n==2 || n==5 ||n==7 || n==6 || n==9 ||n==11 || n==12 || n==13 ||n==15 || n==16)
                       Maze[n][m].wall=1;
                }
                else if(m==5)
                {
                    if(n==2 || n==9 || n==16)
                       Maze[n][m].wall=1;
                }
                else if(m==6)
                {
                    if(n==4 || n==2 || n==5 || (n>=7 &&n<=11) || n==13 || n==14 || n==16)
                       Maze[n][m].wall=1;
                }
                else if(m==8)
                {
                    if(n==2 || n==4 || n==6 ||n==7 || n==8 || n==9 || n==10 ||n==11 || n==12 || n==14 || n==16)
                       Maze[n][m].wall=1;
                }
                else if(m==9)
                {
                    if(n==4 || n==2 || n==6 ||n==12 || n==16 || n==14)
                       Maze[n][m].wall=1;
                }
                else if(m==10)
                {
                    if(n==4 || (n>=6 && n<=12) ||n==14)
                       Maze[n][m].wall=1;
                }
                else if(m==11)
                {
                    if(n==1 || n==2 || n==4 ||n==14 || n==16 || n==17)
                       Maze[n][m].wall=1;
                }
                else if(m==12)
                {
                    if(n==4 || n==6 || n==8 ||n==7 || n==10 || n==12 ||n==11 || n==12 || n==14)
                       Maze[n][m].wall=1;
                }
                else if(m==13)
                {
                    if(n==7 || n==2 || n==11 ||n==16)
                       Maze[n][m].wall=1;
                }
                else if (m==14)
                {
                    if(n==3 || n==2  || n==4 || n==5 ||n==7|| n==9 ||n==11 || n==13 || n==14 ||n==15 || n==16)
                       Maze[n][m].wall=1;
                }
                else if (m==15)
                {
                    if(n==5 || n==7 || n==9 ||n==11 || n==13)
                       Maze[n][m].wall=1;
                }
                else if (m==16)
                {
                    if(n==3 || n==2 || n==1 ||n==5 || n==9 ||n==13 || n==15 || n==17 || n==16)
                       Maze[n][m].wall=1;
                }
                else if (m==17)
                {
                    if(n==5 ||n==7 || n==8 || n==9  || n==10||n==11 || n==13)
                       Maze[n][m].wall=1;
                }
                else if (m==18)
                {
                    if(n==2 || n==5 ||n==7 || n==11 || n==13 ||n==16)
                       Maze[n][m].wall=1;
                }
                else if (m==19)
                {
                    if(n==4 || n==2 || n==5 || n==9 ||n==13 || n==14 || n==16)
                       Maze[n][m].wall=1;
                }
                else if (m==20)
                {
                    if(n==7 || n==9 || n==11)
                       Maze[n][m].wall=1;
                }
                else if(m==21)
                {
                    if(n==2 || n==4|| n==5 || n==6 ||n==7 || n==9 || n==11 || n==12 || n==13 || n==14 || n==16)
                       Maze[n][m].wall=1;
                }
                else if (m==22)
                {
                  if(n==9 || n==2|| n==16)
                       Maze[n][m].wall=1;
                }
                else if(m==23)
                {
                    if( n==3 || n==2 || n==5 || n==6 ||n==8 || n==9 || n==10 || n==12 || n==13 || n==15 || n==16)
                       Maze[n][m].wall=1;
                }
                else
                    Maze[n][m].wall=false;

                Vector2i position(n*30, m*30);
                Maze[n][m].coordinates=position;
                Maze[n][m].cell=new RectangleShape(Vector2f(30,30));

            }
        }
    }

};

MazeAttributes maze;


pthread_mutex_t PlayerMovementLock;
pthread_mutex_t PlayerPalletEatingLock;

pthread_mutex_t BlinkyMovementLock;
pthread_mutex_t PinkyMovementLock;
pthread_mutex_t InkyMovementLock;
pthread_mutex_t ClydeMovementLock;

pthread_mutex_t PlayerGhostCollisionLock;
pthread_mutex_t PlayerPowerCollisionLock;

sem_t GhostSpeedBost;

sem_t GhostHouseKeyLock;
sem_t GhostHousePermitLock;

sem_t GhostPause;

int Lives=3;
int Score = 0;
bool GamePause=false;

Clock Timer;


