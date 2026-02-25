#include "SceneManager.h"

SceneManager::SceneManager()
{

}

void SceneManager::Update(float dt)
{
    if (!currentScene)
        return;

    currentScene->Update(dt);

    auto next = currentScene->GetNextScene();
    if (next)
    {
        currentScene = std::move(next);
    }
}

void SceneManager::Render(sf::RenderWindow& window)
{
    if (currentScene)
        currentScene->Render(window);
}

void SceneManager::ChangeScene(std::unique_ptr<Scene> newScene)
{
    currentScene = std::move(newScene);
}
