#include "Block.h"
#include <iostream>

Block::Block(float x, float y, sf::Color color)
{
    shape.setSize({ 50.f, 50.f });
    shape.setFillColor(color);
    position = { x, y };
    shape.setPosition(position);
    scale = { 1.f, 1.f };
    rotation = 0.f;
}

void Block::Update(float deltaTime)
{
    rotation += 90.f * deltaTime;
    shape.setPosition(position);
    shape.setScale(scale);
    shape.setRotation(rotation);
}

void Block::Draw(sf::RenderWindow& window)
{
    window.draw(shape);
}