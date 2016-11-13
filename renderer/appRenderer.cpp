#include <SDL2/SDL.h>

#define GL3_PROTOTYPES 1
// #define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include "appRenderer.h"

AppRenderer::AppRenderer() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    glewExperimental = GL_TRUE;
    glewInit();

    FT_Library ft;
    if (FT_Init_FreeType(&ft)) {
        printf("ERROR::FREETYPE: Could not init FreeType Library\n");
        // throw smth
    }

}

AppRenderer::~AppRenderer(){}

void AppRenderer::render() {
    glClearColor(1.0, 0., 0., 1.);
    glClear(GL_COLOR_BUFFER_BIT);
}
