#ifndef SETTINGS_H
#define SETTINGS_H

struct Settings {
    int windowNumber;
    bool fullscreen;
};

extern struct Settings settings;

void saveSettings(void);
bool loadSettings(void);

#endif // SETTINGS_H