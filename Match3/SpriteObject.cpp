#include "SpriteObject.h"

void SpriteObject::SetPosition(float x, float y)
{
    GameObject::SetPosition(x, y);  
    sprite.setPosition(position);   
}

void SpriteObject::SetScale(float x, float y)
{
    GameObject::SetScale(x, y);
    sprite.setScale(scale);
}

void SpriteObject::SetRotation(float angle)
{
    GameObject::SetRotation(angle);
    sprite.setRotation(rotation);
}

void SpriteObject::SetTexture(const sf::Texture& tex)
{
    sprite.setTexture(tex);
}

void SpriteObject::SetTexture(const std::string& id)
{
    sprite.setTexture(TextureMgr.Get(id));
}

void SpriteObject::Update(float deltaTime)
{
}

void SpriteObject::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
