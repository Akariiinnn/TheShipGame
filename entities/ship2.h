//
// Created by stagiairedit on 24/06/2022.
//

#ifndef UNTITLED3_SHIP2_H
#define UNTITLED3_SHIP2_H

#include <SDL.h>
#include <iostream>
#include "../render/spritesheet.h"

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

    enum class Orientation {
        LOOKUP,
        LOOKDOWN,
        LOOKLEFT,
        LOOKRIGHT,
        LOOKUPFIRING,
        LOOKDOWNFIRING,
        LOOKLEFTFIRING,
        LOOKRIGHTFIRING
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
    Orientation  m_orientation;

    bool         firing;
    bool         lookup;
    bool         lookdown;
    bool         lookleft;
    bool         lookright;
    SDL_Rect     m_position;
    double       m_x;
    double       m_y;
};
#endif //UNTITLED3_SHIP2_H
