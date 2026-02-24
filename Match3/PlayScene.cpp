#include "PlayScene.h"
#include "Block.h"
#include <iostream>

PlayScene::PlayScene()
{
    AddObject(new Block(100.f, 100.f, sf::Color::Red));
    AddObject(new Block(200.f, 100.f, sf::Color::Blue));
    AddObject(new Block(150.f, 200.f, sf::Color::Green));
}

void PlayScene::HandleEvent(const sf::Event& event)
{
    // 이벤트 처리
    // 예: 마우스 클릭, 키 입력
}

void PlayScene::Update(float deltaTime)
{
    for (auto obj : objects)
    {
        obj->Update(deltaTime);
    }
}

void PlayScene::Render(sf::RenderWindow& window)
{
    for (auto obj : objects)
    {
        obj->Draw(window);
    }
}

void PlayScene::AddObject(GameObject* obj)
{
    objects.push_back(obj);
}
