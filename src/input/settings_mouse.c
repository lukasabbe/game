#include "raylib.h"
#include "../settings.h"

void handleSettingMouseInput(void){
    if(!IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) return;
    Vector2 mousePos = GetMousePosition();
    int toggleX = MeasureText("- Fullscreen: ", 20) + 50;
    int toggleY = 60 - 5;
    int cubeWidth = 30;

    if(mousePos.x >= toggleX && mousePos.x <= toggleX + cubeWidth &&
       mousePos.y >= toggleY && mousePos.y <= toggleY + cubeWidth) {
        settings.fullscreen = !settings.fullscreen;
        saveSettings();
    }

    int buttonX =  MeasureText(strcat("- Monitor: ", GetMonitorName(settings.windowNumber)), 20) + 55;
    int buttonY = 60 + 40 - 5;
    int buttonWidth = 55;
    int buttonHeight = 30;
    if(mousePos.x >= buttonX && mousePos.x <= buttonX + buttonWidth &&
       mousePos.y >= buttonY && mousePos.y <= buttonY + buttonHeight) {
        settings.windowNumber = (settings.windowNumber + 1) % GetMonitorCount();
        TraceLog(LOG_INFO, TextFormat("Switched to monitor %d", settings.windowNumber));
        saveSettings();
    }
}