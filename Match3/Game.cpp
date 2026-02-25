#include "Game.h"
#include "InputManager.h"
#include "FontManager.h"
#include "TitleScene.h"
#include "Define.h"

Game::Game(int width, int height, const std::string& title)
    : window(sf::VideoMode(width, height), title), sceneMgr()
{
}

void Game::Init()
{
    FontMgr.Load(FontKey::Default, "resources/font/NotoSansKR-Regular.ttf");
    sceneMgr.ChangeScene(std::make_unique<TitleScene>());
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

        InputMgr.HandleEvent(event);
    }
}

void Game::Update(float deltaTime)
{
    sceneMgr.Update(deltaTime);
    InputMgr.Update();
}

void Game::Render()
{
    window.clear();
    sceneMgr.Render(window);
    window.display();
}