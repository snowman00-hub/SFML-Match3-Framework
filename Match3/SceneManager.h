#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"

class SceneManager
{
public:
	SceneManager();
	void HandleEvent(const sf::Event& event);
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
	void ChangeScene(Scene* newScene);

private:
	Scene* currentScene = nullptr;
};