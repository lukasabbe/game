#include "raylib.h"
#include "../settings.h"
#include "../input/settings_mouse.h"

void drawToggle(bool value, int x, int y) {
    DrawRectangle(x, y, 30, 30, LIGHTGRAY);
    if(value) {
        struct Vector2 left_top_corner = {x, y};
        struct Vector2 right_top_corner = {x + 30, y};
        struct Vector2 right_bottom_corner = {x + 30, y + 30};
        struct Vector2 left_bottom_corner = {x, y + 30};
        DrawLineEx(left_top_corner, right_bottom_corner, 3, RED);
        DrawLineEx(right_top_corner, left_bottom_corner, 3, RED);
    }
}

void drawNextMonitorButton(int x, int y) {
    DrawRectangle(x, y, 55, 30, LIGHTGRAY);
    DrawText("Next", x + 5, y + 5, 20, DARKGRAY);
}

void renderSettings(void) {

    ClearBackground(RAYWHITE);

    int posX = 50;
    int menuPosY = 10;
    int listPosY = 60;

    int menuFontSize = 30;
    int listFontSize = 20;

    char MenuTitle[] = "Settings Menu";
    char FullscreenLabel[] = "- Fullscreen: ";

    DrawText(MenuTitle, posX, menuPosY, menuFontSize, BLACK);
    DrawText(FullscreenLabel, posX, listPosY, listFontSize, DARKGRAY);

    drawToggle(settings.fullscreen, MeasureText(FullscreenLabel, listFontSize) + 50, listPosY - 5);

    char MonitorLabel[] = "- Monitor: ";
    strcat(MonitorLabel, GetMonitorName(settings.windowNumber));

    DrawText(MonitorLabel, posX, listPosY + 40, listFontSize, DARKGRAY);

    drawNextMonitorButton(MeasureText(MonitorLabel, listFontSize) + 55, listPosY + 40 - 5);

    handleSettingMouseInput();
}