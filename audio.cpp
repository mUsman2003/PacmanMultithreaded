#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/Audio.hpp>
#include <cstring>
#include <semaphore.h>
using namespace std;

void* Chomp(void* arg)
{
    sf::SoundBuffer buffer;
    buffer.loadFromFile("assets/audio/pacman_chomp.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(25);
    sound.play();
    while (sound.getStatus() == sf::Sound::Playing) {
        // Do nothing
    }
    pthread_exit(0);
}

void* GhostDeath(void* arg)
{
    sf::SoundBuffer buffer;
    buffer.loadFromFile("assets/audio/pacman_eatghost.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(200);
    sound.play();
    while (sound.getStatus() == sf::Sound::Playing) {
        // Do nothing
    }
    pthread_exit(0);
}

void* EatFruit(void* arg)
{
    sf::SoundBuffer buffer;
    buffer.loadFromFile("assets/audio/pacman_eatfruit.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(200);
    sound.play();
    while (sound.getStatus() == sf::Sound::Playing) {
        // Do nothing
    }
    pthread_exit(0);
}

void* Death(void* arg)
{
    sf::SoundBuffer buffer;
    buffer.loadFromFile("assets/audio/pacman_death.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(200);
    sound.play();
    while (sound.getStatus() == sf::Sound::Playing) {
        // Do nothing
    }
    pthread_exit(0);
}
