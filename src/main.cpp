#include <iostream>
#include <memory>

#include "raylib.h"
#include "raygui.h"
#include "imgui.h"
#include "rlImGui.h"

#include "gameinstance.h"


int main(void)
{
    std::weak_ptr<GameInstance> gameInstance = GameInstance::getInstance();
    gameInstance.lock()->mainGameInstance();

    return 0;
}
