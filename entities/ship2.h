//
// Created by stagiairedit on 24/06/2022.
//

#ifndef UNTITLED3_SHIP2_H
#define UNTITLED3_SHIP2_H

#include <SDL.h>
#include <iostream>
#include "../render/spritesheet.h"

//Ship2 class header

class Ship2
{
public:
    enum class Direction
    {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONEFIRING,
        UPFIRING,
        DOWNFIRING,
        LEFTFIRING,
        RIGHTFIRING
    };

    Ship2();
    ~Ship2() = default;

    SDL_Rect getPosition();

    void handle_events(SDL_Event const &event);
    void update(double delta_time);
    void draw(SDL_Surface *window_surface);
    void start();
private:
    Spritesheet  m_spritesheet;
    Direction    m_direction;
    SDL_Rect     m_position;
    double       m_x;
    double       m_y;
};
#endif //UNTITLED3_SHIP2_H
