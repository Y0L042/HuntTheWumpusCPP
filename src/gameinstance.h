#pragma once

#include <memory>

class GameInstance
{
public:
    GameInstance();
    ~GameInstance();

    static std::weak_ptr<GameInstance> getInstance();

    int mainGameInstance();
    void Ready();
    void Update(double delta);
    void Draw(double delta);


    static std::shared_ptr<GameInstance> gameInstance;

private:

    GameInstance(const GameInstance&) = delete;
    GameInstance& operator=(const GameInstance&) = delete;
};
