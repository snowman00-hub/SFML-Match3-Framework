#include "TitleScene.h"
#include "PlayScene.h"

TitleScene::TitleScene()
{
}

void TitleScene::Init()
{
    auto bg = CreateObject<SpriteObject>();
    bg->SetTexture("TitleBG");
    bg->SetPosition(0, 0);

    text.setFont(FontMgr.Get(FontKey::Default));
    text.setString(L"안녕하세요");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setPosition(200.f, 200.f);
}

void TitleScene::LoadResources()
{     
    TextureMgr.Load("TitleBG", "resources/sprite/title_background.jpg");
}

void TitleScene::UnloadResources()
{
    TextureMgr.Unload("TitleBG");
}

void TitleScene::Update(float deltaTime)
{
    if (InputMgr.getKeyDown(sf::Keyboard::Num2))
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