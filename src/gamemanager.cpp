#include "gamemanager.h"

std::shared_ptr<GameManager> GameManager::instance = nullptr;

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

std::weak_ptr<GameManager> GameManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = std::make_shared<GameManager>();
    }
    return instance;
}
