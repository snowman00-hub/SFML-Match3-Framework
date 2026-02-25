#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <iostream>

class FontManager
{
private:
    std::unordered_map<std::string, sf::Font> fonts;

    FontManager() = default;
    ~FontManager() = default;

public:
    static FontManager& getInstance()
    {
        static FontManager instance;
        return instance;
    }

    bool Load(const std::string& id, const std::string& path)
    {
        sf::Font font;

        if (!font.loadFromFile(path))
        {
            std::cout << "폰트 로드 실패: " << path << std::endl;
            return false;
        }

        fonts[id] = font;
        return true;
    }

    sf::Font& Get(const std::string& id)
    {
        return fonts.at(id); // 없으면 예외 발생
    }
};

#define FontMgr FontManager::getInstance()