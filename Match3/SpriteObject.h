#pragma once
#include "GameObject.h"
#include "TextureManager.h"

class SpriteObject : public GameObject
{
public:
    SpriteObject() = default;
    ~SpriteObject() override = default;

    void SetPosition(float x, float y) override;
    void SetScale(float x, float y) override;
    void SetRotation(float angle) override;

    void SetTexture(const sf::Texture& tex);
    void SetTexture(const std::string& id);
    void Update(float deltaTime) override;
    void Draw(sf::RenderWindow& window) override;

private:
    sf::Sprite sprite;
};