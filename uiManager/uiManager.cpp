#include "uiManager.hpp"

#include <stdio.h>

UiManager::UiManager() {

}

UiManager::~UiManager() {

}

int UiManager::addButton() {
    Button* b = new Button();
    this->buttons.push_back(b);
    return 0;
}
