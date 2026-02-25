#include "TitleScene.h"
#include "PlayScene.h"

TitleScene::TitleScene()
{
    text.setFont(FontMgr.Get(FontKey::Default));
    text.setString(L"안녕하세요");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setPosition(200.f, 200.f);
}

void TitleScene::Update(float deltaTime)
{
    if (InputMgr.getKeyDown(sf::Keyboard::Space))
    {
        nextScene = std::make_unique<PlayScene>();
    }

    for (auto& obj : objects)
    {
        obj->Update(deltaTime);
    }
}

void TitleScene::Render(sf::RenderWindow& window)
{
    for (auto& obj : objects)
    {
        obj->Draw(window);
    }
    window.draw(text);
}