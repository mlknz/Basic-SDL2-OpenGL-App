#ifndef __animalFarm_AppManager_h__
#define __animalFarm_AppManager_h__

#include <SDL2/SDL.h>
#include "controls/appControls.h"
#include "renderer/appRenderer.h"

class AppManager {
public:
    AppManager();
    ~AppManager();

    void runMainLoop();

private:
    AppControls* controls;
    AppRenderer* renderer;

    SDL_Window* gWindow = nullptr;
    SDL_GLContext glContext = nullptr;

    bool quit = false;
};

#endif
