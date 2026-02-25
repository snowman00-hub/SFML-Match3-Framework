#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <iostream>

class TextureManager
{
private:
    std::unordered_map<std::string, sf::Texture> textures;

    TextureManager() = default;
    ~TextureManager() = default;

public:
    static TextureManager& getInstance()
    {
        static TextureManager instance;
        return instance;
    }

    bool Load(const std::string& id, const std::string& path)
    {
        sf::Texture tex;
        if (!tex.loadFromFile(path))
        {
            std::cout << "텍스처 로드 실패: " << path << std::endl;
            return false;
        }
        textures[id] = tex;
        return true;
    }

    bool Unload(const std::string& id)
    {
        auto it = textures.find(id);
        if (it != textures.end())
        {
            textures.erase(it);
            return true;
        }
        else
        {
            std::cout << "텍스처 언로드 실패: " << id << " 존재하지 않음\n";
            return false;
        }
    }

    sf::Texture& Get(const std::string& id)
    {
        return textures.at(id); // 없으면 예외 발생
    }
};

#define TextureMgr TextureManager::getInstance()