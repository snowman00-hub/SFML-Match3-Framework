#include "Game.h"

Game::Game(int width, int height, const std::string& title)
    : window(sf::VideoMode(width, height), title), sceneMgr()
{
}

void Game::Play()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        ProcessEvent();
        Update(deltaTime);
        Render();
    }
}

void Game::ProcessEvent()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        sceneMgr.HandleEvent(event);
    }
}

void Game::Update(float deltaTime)
{
    sceneMgr.Update(deltaTime);
}

void Game::Render()
{
    window.clear();
    sceneMgr.Render(window);
    window.display();
}