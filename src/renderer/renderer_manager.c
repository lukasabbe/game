#include "raylib.h"
#include "settings_renderer.h"
#include "game_renderer.h"
#include "renderer_manager.h"

void render(MenuState state) {
    BeginDrawing();

    switch (state) {
        case STATE_SETTINGS:
            renderSettings();
            break;
        case STATE_GAME:
            renderGame();
            break;
    }

    EndDrawing();
}