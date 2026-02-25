#pragma once
#include "Scene.h"
#include <vector>

class PlayScene : public Scene
{
public:
    PlayScene();
    virtual ~PlayScene() = default;

    void Init() override;
    void LoadResources() override;
    void UnloadResources() override;

    void Update(float deltaTime) override;
    void Render(sf::RenderWindow& window) override;
};