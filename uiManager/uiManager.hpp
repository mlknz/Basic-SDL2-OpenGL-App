#ifndef __animalFarm_UiManager_h__
#define __animalFarm_UiManager_h__

#include "button.hpp"
#include <vector>

class UiManager {
public:
    UiManager();
    ~UiManager();

    int addButton();
    std::vector<Button*> buttons;
private:
};

#endif
