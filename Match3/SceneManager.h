#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"

class SceneManager
{
public:
	SceneManager();
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
	void ChangeScene(std::unique_ptr<Scene> newScene);

private:
	std::unique_ptr<Scene> currentScene;
};