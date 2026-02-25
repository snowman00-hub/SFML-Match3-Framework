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
        ChangeScene(std::move(next));
    }
}

void SceneManager::Render(sf::RenderWindow& window)
{
    if (currentScene)
        currentScene->Render(window);
}

void SceneManager::ChangeScene(std::unique_ptr<Scene> newScene)
{
    if (currentScene)
        currentScene->UnloadResources(); // 이전 씬 리소스 해제

    currentScene = std::move(newScene);

    if (currentScene)
    {
        currentScene->LoadResources();   // 새 씬 리소스 로드
        currentScene->Init();
    }
}
