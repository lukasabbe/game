#include "raylib.h"
#include "../settings.h"

void handleSettingMouseInput(void){
    if(!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) return;
    TraceLog(LOG_INFO, "Mouse Clicked");
    Vector2 mousePos = GetMousePosition();
    int toggleX = MeasureText("- Fullscreen: ", 20) + 50;
    int toggleY = 60 - 5;
    int cubeWidth = 30;
    if(mousePos.x >= toggleX && mousePos.x <= toggleX + cubeWidth &&
       mousePos.y >= toggleY && mousePos.y <= toggleY + cubeWidth) {
        settings.fullscreen = !settings.fullscreen;
        TraceLog(LOG_INFO, "Toggled fullscreen to %d", settings.fullscreen);
        saveSettings();
    }

}