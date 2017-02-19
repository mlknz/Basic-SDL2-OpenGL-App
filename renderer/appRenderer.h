#ifndef __animalFarm_AppRenderer_h__
#define __animalFarm_AppRenderer_h__

class AppRenderer {
public:
    AppRenderer();
    ~AppRenderer();

    void render();
    void initTextRenderer();

private:

    // void RenderText(Shader &s, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color);
};

#endif
