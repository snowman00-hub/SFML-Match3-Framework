#include "PlayScene.h"
#include "Block.h"
#include "TitleScene.h"
#include <iostream>

PlayScene::PlayScene()
{
    auto block1 = CreateObject<Block>(100.f, 100.f, sf::Color::Red);
    CreateObject<Block>(200.f, 100.f, sf::Color::Blue);
    CreateObject<Block>(150.f, 200.f, sf::Color::Green);
}

void PlayScene::Update(float deltaTime)
{
    if (InputMgr.getKeyDown(sf::Keyboard::Space))
    {
        nextScene = std::make_unique<TitleScene>();
    }

    for (auto& obj : objects)
    {
        obj->Update(deltaTime);
    }
}

void PlayScene::Render(sf::RenderWindow& window)
{
    for (auto& obj : objects)
    {
        obj->Draw(window);
    }
}
