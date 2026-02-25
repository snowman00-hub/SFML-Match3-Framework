#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SpriteObject.h"
#include "TextureManager.h"

class Scene
{
public:
	virtual ~Scene() = default;

	virtual void Init() = 0;
	virtual void LoadResources() {}    // 씬 진입 시 호출
	virtual void UnloadResources() {}  // 씬 종료 시 호출

	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow& window) = 0;

	std::unique_ptr<Scene> GetNextScene() { return std::move(nextScene); }

	template<typename T, typename... Args>
	T* CreateObject(Args&&... args)
	{
		auto obj = std::make_unique<T>(std::forward<Args>(args)...); // std::forward<Args>(arg)... 은 lvalue rvalue를 보존해서 넘김.
		T* ptr = obj.get();
		objects.push_back(std::move(obj));
		return ptr;
	}

protected:
	std::unique_ptr<Scene> nextScene;
	std::vector<std::unique_ptr<GameObject>> objects;
};