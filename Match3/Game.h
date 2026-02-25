#pragma once
#include <SFML/Graphics.hpp>
#include "SceneManager.h"

class Game
{
public:
    Game(int width, int height, const std::string& title);
    void Init();
    void Play();

private:
    void ProcessEvent();
    void Update(float deltaTime);
    void Render();

private:
    sf::RenderWindow window;
    SceneManager sceneMgr;
};