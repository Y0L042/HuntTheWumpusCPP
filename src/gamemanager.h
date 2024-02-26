#pragma once
#include <memory>

class GameManager
{
public:
    GameManager();
    ~GameManager();
    static std::weak_ptr<GameManager> getInstance();

private:
    static std::shared_ptr<GameManager> instance;
};
