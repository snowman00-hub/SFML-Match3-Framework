#pragma once
#include "Scene.h"
#include <vector>

class TitleScene : public Scene
{
public:
    TitleScene();
    virtual ~TitleScene() = default;

    void Init() override;
    void LoadResources() override;
    void UnloadResources() override;

    void Update(float deltaTime) override;
    void Render(sf::RenderWindow& window) override;

private:
    sf::Text text;
};