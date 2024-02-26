#include "gameinstance.h"
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "imgui.h"
#include "rlImGui.h"

#include <vector>


// Forward declarations
void Ready_GameObjects();
void ReadySpawnedGameObjects();
void Update_GameObjects(double delta);
void Draw_GameObjects(double delta);
void EndOfFrame_GameObjects();

std::shared_ptr<GameInstance> GameInstance::gameInstance = nullptr;

GameInstance::GameInstance()
{

}

GameInstance::~GameInstance()
{

}

int GameInstance::mainGameInstance()
{
    int windowWidth = 750;
    int windowHeight = 700;
    int targetFPS = 144;

    Color grey = {29, 29, 27, 255};

    InitWindow(windowWidth, windowHeight, "Space Invaders");
    SetTargetFPS(targetFPS);
    rlImGuiSetup(true);

    Ready();
    Ready_GameObjects();

    while(!WindowShouldClose())
    {
        double delta = GetFrameTime();

        BeginDrawing();
        rlImGuiBegin();
        ClearBackground(grey);

        ReadySpawnedGameObjects();

        Update(delta);
        Update_GameObjects(delta);

        Draw(delta);
        Draw_GameObjects(delta);

        EndOfFrame_GameObjects();
        rlImGuiEnd();
        EndDrawing();
    }
    rlImGuiShutdown();
    CloseWindow();
}

void Ready_GameObjects()
{
//    Game::Ready();
}

void ReadySpawnedGameObjects()
{
//    Game::ProcessReadyQueue();
}

void Update_GameObjects(double delta)
{
//    Game::Update(delta);
}

void Draw_GameObjects(double delta)
{
//    Game::Draw(delta);
}

void EndOfFrame_GameObjects()
{
//    Game::ProcessDestructionQueue();
//    Game::ProcessAdditionsQueue();
}

std::weak_ptr<GameInstance> GameInstance::getInstance()
{
    if (!gameInstance)
    {
        gameInstance = std::make_shared<GameInstance>();
    }
    return gameInstance;
}

void GameInstance::Ready()
{


}

void GameInstance::Update(double delta)
{

}


void GameInstance::Draw(double delta)
{

}
