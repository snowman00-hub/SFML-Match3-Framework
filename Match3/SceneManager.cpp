#include "SceneManager.h"
#include "PlayScene.h"

SceneManager::SceneManager()
{
    currentScene = new PlayScene(); // 시작 씬
}

void SceneManager::HandleEvent(const sf::Event& event)
{
    if (currentScene)
        currentScene->HandleEvent(event);
}

void SceneManager::Update(float deltaTime)
{
    if (currentScene)
        currentScene->Update(deltaTime);
}

void SceneManager::Render(sf::RenderWindow& window)
{
    if (currentScene)
        currentScene->Render(window);
}

void SceneManager::ChangeScene(Scene* newScene)
{
    delete currentScene;
    currentScene = newScene;
}