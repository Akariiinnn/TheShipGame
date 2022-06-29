//
// Created by stagiairedit on 23/06/2022.
//

#ifndef UNTITLED3_APPLICATION_H
#define UNTITLED3_APPLICATION_H
#include <iostream>
#include <SDL.h>
#include "../entities/ship.h"
#include "../entities/ship2.h"
#include <memory>

class Application
{
public:
    Application();
    ~Application();

    void loop();
    void update(double delta_time);
    void draw();

    void start();

    SDL_Renderer *getRenderer();

private:
    Ship m_ship;
    Ship2 m_ship2;
    SDL_Window   *m_window;
    SDL_Surface  *m_window_surface;
    SDL_Event     m_window_event;
};

#endif //UNTITLED3_APPLICATION_H
