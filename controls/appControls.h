#ifndef __animalFarm_AppControls_h__
#define __animalFarm_AppControls_h__

class AppControls {
public:
    AppControls();
    AppControls(bool*);
    ~AppControls();

    void update();

private:
    SDL_Event e;
    bool* quit;
};

#endif
