#pragma once
#include "Scene.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <vector>

class PlayScene : public Scene
{
public:
    PlayScene();
    virtual ~PlayScene() = default;

    void HandleEvent(const sf::Event& event) override;
    void Update(float deltaTime) override;
    void Render(sf::RenderWindow& window) override;

    void AddObject(GameObject* obj); 

private:
    std::vector<GameObject*> objects; // 게임 오브젝트 모음
};