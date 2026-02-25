#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

class InputManager {
private:
    std::unordered_map<sf::Keyboard::Key, bool> keyCurrent;
    std::unordered_map<sf::Keyboard::Key, bool> keyPrevious;

    std::unordered_map<sf::Mouse::Button, bool> mouseCurrent;
    std::unordered_map<sf::Mouse::Button, bool> mousePrevious;

    InputManager() = default;

public:
    static InputManager& getInstance() {
        static InputManager instance;
        return instance;
    }

    void HandleEvent(const sf::Event& event) {
        // 키 이벤트 처리 (누름/뗌)
        if (event.type == sf::Event::KeyPressed)
            keyCurrent[event.key.code] = true;
        else if (event.type == sf::Event::KeyReleased)
            keyCurrent[event.key.code] = false;

        // 마우스 이벤트 처리
        if (event.type == sf::Event::MouseButtonPressed)
            mouseCurrent[event.mouseButton.button] = true;
        else if (event.type == sf::Event::MouseButtonReleased)
            mouseCurrent[event.mouseButton.button] = false;
    }

    void Update() {
        // 이전 상태 저장
        keyPrevious = keyCurrent;
        mousePrevious = mouseCurrent;
    }

    // 키 상태 체크
    bool getKey(sf::Keyboard::Key key) { return keyCurrent[key]; }
    bool getKeyDown(sf::Keyboard::Key key) { return keyCurrent[key] && !keyPrevious[key]; }
    bool getKeyUp(sf::Keyboard::Key key) { return !keyCurrent[key] && keyPrevious[key]; }

    // 마우스 상태 체크
    bool getMouse(sf::Mouse::Button button) { return mouseCurrent[button]; }
    bool getMouseDown(sf::Mouse::Button button) { return mouseCurrent[button] && !mousePrevious[button]; }
    bool getMouseUp(sf::Mouse::Button button) { return !mouseCurrent[button] && mousePrevious[button]; }
};

#define InputMgr InputManager::getInstance()