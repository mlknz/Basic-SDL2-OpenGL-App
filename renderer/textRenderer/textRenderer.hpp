#ifndef __animalFarm_TextRenderer_h__
#define __animalFarm_TextRenderer_h__

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

class TextRenderer {
public:
    TextRenderer();
    ~TextRenderer();

    // todo: make each renderText to be 1 draw call
    void renderText(std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);

    void render();
private:

};

#endif
