#pragma once
#include <SFML/Graphics.hpp>
#include "InputManager.h"
#include "FontManager.h"
#include "Define.h"

class GameObject
{
public:
    GameObject() = default;
    virtual ~GameObject() = default;

    virtual void Update(float deltaTime) {}
    virtual void Draw(sf::RenderWindow& window) {}

    virtual void SetPosition(float x, float y) { position = { x, y }; }
    virtual void SetScale(float x, float y) { scale = { x, y }; }
    virtual void SetRotation(float angle) { rotation = angle; }

    sf::Vector2f GetPosition() const { return position; }
    sf::Vector2f GetScale() const { return scale; }
    float GetRotation() const { return rotation; }

protected:
    sf::Vector2f position{0.f, 0.f};
    sf::Vector2f scale{ 1.f, 1.f };
    float rotation{ 0.f };
};