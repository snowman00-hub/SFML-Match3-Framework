#pragma once
#include "Scene.h"
#include <vector>

class TitleScene : public Scene
{
public:
    TitleScene();
    virtual ~TitleScene() = default;

    void Update(float deltaTime) override;
    void Render(sf::RenderWindow& window) override;

private:
    sf::Text text;
};