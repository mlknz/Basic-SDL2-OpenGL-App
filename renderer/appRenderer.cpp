#include "appRenderer.hpp"

#include <SDL2/SDL.h>

// glew
#define GL3_PROTOTYPES 1
// #define GLEW_STATIC
#include <GL/glew.h>
#include <GL/glu.h>
#include <GL/gl.h>
// std
#include <map>
#include <string>
#include <vector> // tmp
#include <utility> // for std::pair
// glm
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

AppRenderer::AppRenderer() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    glewExperimental = GL_TRUE;
    glewInit();

    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.4, 0., 0., 1.);


    this->textRenderer = new TextRenderer();

}

AppRenderer::~AppRenderer(){}

void AppRenderer::render() {

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    this->textRenderer->renderText("Rendering text no joke.", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));

}


