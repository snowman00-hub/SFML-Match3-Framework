#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Block : public GameObject
{
public:
    Block(float x, float y, sf::Color color);
    void Update(float deltaTime) override;
    void Draw(sf::RenderWindow& window) override;

private:
    sf::RectangleShape shape;
};