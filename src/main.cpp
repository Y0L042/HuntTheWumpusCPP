#include <iostream>
#include <memory>
#include <cmath>

#include "raylib.h"
#include "raygui.h"
#include "imgui.h"
#include "rlImGui.h"

#include "gameinstance.h"

void ready();
void update(double delta);
void draw(double delta);
void createCaveNetwork();
void drawCaves();

typedef struct Cave
{
    char name[20];
    struct Cave* linkedCaves[3];
    Vector2 position;
    // caveEvent;
} Cave;

struct Cave* caveNetwork[20];

const int caveNetworkArray[20][3] =
{
  {1, 4, 7},   {0, 2, 9},   {1, 3, 11}, {2, 4, 13}, {0, 3, 5},
  {4, 6, 14},  {5, 7, 16},  {0, 6, 8},  {7, 9, 17},     {1, 8, 10},
  {9, 11, 18}, {2, 10, 12}, {11, 13, 19},  {3, 12, 14}, {5, 13, 15},
  {14, 16, 19}, {6, 15, 17},  {8, 16, 18}, {10, 17, 19}, {12, 15, 18}
};

typedef struct Player
{
    Cave* currentCave;
    int arrowCount;
} Player;

int windowWidth = 750;
int windowHeight = 700;
int targetFPS = 144;
Color grey = {29, 29, 27, 255};

int main(void)
{


    InitWindow(windowWidth, windowHeight, "Hunt The Wumpus");
    SetTargetFPS(targetFPS);
    rlImGuiSetup(true);

    ready();

    while(!WindowShouldClose())
    {
        double delta = GetFrameTime();

        BeginDrawing();
        rlImGuiBegin();

        ClearBackground(grey);

        update(delta);
        draw(delta);

        rlImGuiEnd();
        EndDrawing();
    }
    rlImGuiShutdown();
    CloseWindow();
}

void ready()
{
    createCaveNetwork();
}

void update(double delta)
{

}

void draw(double delta)
{
    drawCaves();
}

void createCaveNetwork()
{
    int caveCount = 20;
    int gridRows = 4; // Number of rows in the grid
    int gridCols = 5; // Number of columns in the grid

    // Calculate spacing between caves
    int horizontalSpacing = windowWidth / (gridCols + 1);
    int verticalSpacing = windowHeight / (gridRows + 1);

    for (int i = 0; i < caveCount; i++)
    {
        caveNetwork[i] = new Cave;

        // Calculate grid position
        int row = i / gridCols;
        int col = i % gridCols;

        // Assign position based on grid position
        caveNetwork[i]->position.x = (col + 1) * horizontalSpacing;
        caveNetwork[i]->position.y = (row + 1) * verticalSpacing;
    }

    for (int caveIdx = 0; caveIdx < caveCount; caveIdx++)
    {
        Cave* cave = caveNetwork[caveIdx];
        for (int linkedCaveIdx = 0; linkedCaveIdx < 3; linkedCaveIdx++)
        {
            cave->linkedCaves[linkedCaveIdx] = caveNetwork[caveNetworkArray[caveIdx][linkedCaveIdx]];
        }
    }
}

void drawCaves()
{
    int caveCount = 20;
    int caveRadius = 10; // Radius of the circle representing the cave

    // Draw each cave
    for (int i = 0; i < caveCount; i++)
    {
        Cave* cave = caveNetwork[i];
        DrawCircle(cave->position.x, cave->position.y, caveRadius, RED);

        // Draw lines to linked caves
        for (int j = 0; j < 3; j++)
        {
            Cave* linkedCave = cave->linkedCaves[j];
            if (linkedCave != nullptr) // Check if the linked cave exists
            {
                DrawLine(cave->position.x, cave->position.y,
                         linkedCave->position.x, linkedCave->position.y, GREEN);
            }
        }
    }
}
