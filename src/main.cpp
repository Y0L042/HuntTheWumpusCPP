#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <iostream>
#include "imgui.h"
#include "rlImGui.h"


int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");
    rlImGuiSetup(true);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        rlImGuiBegin();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        if ( GuiButton( (Rectangle){ 20, 20, 20, 20 }, "Press me!" ) )
        {
            std::cout << "Pressed";
        }
        ImGui::Text("Hello, world %d", 123);
        rlImGuiEnd();
        EndDrawing();
    }
    rlImGuiShutdown();
    CloseWindow();

    return 0;
}
