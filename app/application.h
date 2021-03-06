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
#include "../entities/meteorite.h"
#include "../render/background.h"
#include "mouse.h"

//Application class functions

class Application
{
public:
    Application(int difficulty);
    ~Application();

    void loop();
    void menu();
    void menu_update(double);
    void menu_draw();
    void update(double delta_time);
    void draw();
    int i;
    void start();
    static int getWindowWidth();
    static int getWindowHeight();
    SDL_Renderer *getRenderer();

private:
    int                  m_difficulty;
    Ship                 m_ship;
    Ship2                m_ship2;
    Meteorite            m_meteorite;
    Background          *m_background;
    Background          *m_background2;
    SDL_Window          *m_window;
    SDL_Surface         *m_window_icon;
    SDL_Surface         *m_window_surface;
    SDL_Event            m_window_event;
    Mouse                m_mouse;
};

#endif //UNTITLED3_APPLICATION_H
