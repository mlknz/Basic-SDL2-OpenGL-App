#ifndef __animalFarm_AppRenderer_h__
#define __animalFarm_AppRenderer_h__

#include "textRenderer/textRenderer.hpp"

class AppRenderer {
public:
    TextRenderer* textRenderer;

    AppRenderer();
    ~AppRenderer();


    void render();


private:
};

#endif
