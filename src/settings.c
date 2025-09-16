#include "raylib.h"
#include <stdlib.h>
#include <string.h>
#include "settings.h"

struct Settings settings = {
    .windowNumber = 0,
    .fullscreen = false
};


void applySettings(void) {
    SetWindowSize(1920, 1080);
    ToggleFullscreen();
}

void saveSettings(void) {
    int dataSize = sizeof(settings);
    unsigned char *data = (unsigned char *) &settings;
    SaveFileData("settings.dat", data, dataSize);
    applySettings();

}

bool loadSettings(void) {
    int dataSize = 0;
    unsigned char *data = LoadFileData("settings.dat", &dataSize);
    
    if (data != NULL && dataSize == sizeof(settings)) {
        memcpy(&settings, data, sizeof(settings));
        UnloadFileData(data);
        applySettings();
        return true;
    } else {
        UnloadFileData(data);
        return false;
    }
}
