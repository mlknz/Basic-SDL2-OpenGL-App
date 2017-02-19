#ifndef __animalFarm_AppRenderer_h__
#define __animalFarm_AppRenderer_h__

#include "textRenderer/textRenderer.hpp"
#include "../uiManager/uiManager.hpp"

class AppRenderer {
public:
    TextRenderer* textRenderer;

    AppRenderer(UiManager*);
    ~AppRenderer();


    void render();

private:
    UiManager* uiManager;
};

#endif
