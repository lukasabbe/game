#include "raylib.h"
#include "renderer/renderer_manager.h"
#include "settings.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const char title[] = "Game";

    InitWindow(screenWidth, screenHeight, title);

    SetTargetFPS(60);

    bool loaded = loadSettings();

    while (!WindowShouldClose())
    {
        if(loaded){
            render(STATE_GAME);
        }else{
            render(STATE_SETTINGS);
        }
    }

    CloseWindow();        // Close window and OpenGL context

    return 0;
}