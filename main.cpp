#include "utils/appManager.h"

#include <stdio.h>
#include <string>

int main( int argc, char* args[] )
{
    AppManager* app = nullptr;

    try {
       app = new AppManager();
    } catch (const std::exception& e) {
        printf(e.what());
        return -1;
    }

    app->runMainLoop();

    return 0;
}
