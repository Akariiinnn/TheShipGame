//
// Created by stagiairedit on 24/06/2022.
//

#ifndef UNTITLED3_SHIP_H
#define UNTITLED3_SHIP_H

#include <SDL.h>
#include <iostream>
#include "../render/spritesheet.h"

class Ship
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

    enum class Orientation {
        NORTH,
        SOUTH,
        EAST,
        WEST
    };

    Ship();
    ~Ship() = default;

    SDL_Rect getPosition();

    void handle_events(SDL_Event const &event);
    void update(double delta_time);
    void draw(SDL_Surface *window_surface);
    Orientation getOrientation();
private:
    Spritesheet  m_spritesheet;
    Direction    m_direction;
    Orientation  m_orientation;

    SDL_Rect     m_position;
    double       m_x;
    double       m_y;
};
#endif //UNTITLED3_SHIP_H
