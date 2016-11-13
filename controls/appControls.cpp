#include <SDL2/SDL.h>

#include "appControls.h"

AppControls::AppControls(bool* quit) {
    this->quit = quit;
}

AppControls::~AppControls() {

}

void AppControls::update() {
    *(this->quit) = false;
    while( SDL_PollEvent( &e ) != 0 )
    {
        if( this->e.type == SDL_QUIT ) {
            *(this->quit) = true;
        } else if ( this->e.type == SDL_KEYDOWN )
        {
            //Select surfaces based on key press
            switch( this->e.key.keysym.sym )
            {
                case SDLK_ESCAPE:
                *(this->quit) = true;
                break;

                case SDLK_UP:
                printf("up\n");
                break;

                case SDLK_DOWN:
                printf("down\n");
                break;

                case SDLK_LEFT:
                printf("left\n");
                // SDL_SetWindowSize(app.gWindow, 300, 300);
                break;

                case SDLK_RIGHT:
                printf("right\n");
                // SDL_SetWindowSize(app.gWindow, 600, 600);
                break;

                default:
                printf("default keypress");
                break;
            }
        }
    }
}
