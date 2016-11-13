#include "appManager.h"

#include <stdio.h>
#include <string>
#include <stdexcept>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

AppManager::AppManager() {
    bool success = true;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {

        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;

    } else {

//        SDL_DisplayMode DM;
//        SDL_GetCurrentDisplayMode(0, &DM);
//        auto screenWidth = DM.w;
//        auto screenHeight = DM.h;

        this->gWindow = SDL_CreateWindow( "Animal Farm", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL );
        // SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_FULLSCREEN); // SDL_WINDOW_FULLSCREEN, SDL_WINDOW_FULLSCREEN_DESKTOP or 0;
        if( this->gWindow == NULL ) {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        } else {
            this->glContext = SDL_GL_CreateContext(this->gWindow);

            if ( this->glContext == NULL ) {
                printf( "OpenGL context couldn't be initialized! SDL_Error: %s\n", SDL_GetError() );
                success = false;
            } else {
                this->controls = new AppControls(&(this->quit));
                this->renderer = new AppRenderer();
            }
        }

    }

    if (!success) throw std::runtime_error("Failed to initialize!\n");
}

AppManager::~AppManager() {
    SDL_DestroyWindow( this->gWindow );
    this->gWindow = NULL;

    SDL_Quit();
}

void AppManager::runMainLoop() {
    while (!this->quit)
    {
        this->controls->update();

        this->renderer->render();

        SDL_GL_SwapWindow(this->gWindow);
    }
}

