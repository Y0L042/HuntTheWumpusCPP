#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <iostream>


int main(void)
{
    //rlImGuiSetup(true);
    InitWindow(800, 450, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            if ( GuiButton( (Rectangle){ 20, 20, 20, 20 }, "Press me!" ) )
            {
                std::cout << "Pressed";
            }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
