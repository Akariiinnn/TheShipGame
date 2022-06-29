//
// Created by stagiairedit on 29/06/2022.
//

#ifndef TESTSDL_METEORITE_H
#define TESTSDL_METEORITE_H


#include <SDL.h>
#include "../render/spritesheet.h"

class Meteorite {
public:
    Meteorite();
    ~Meteorite() = default;

    SDL_Rect getPosition();

    void update(double delta_time);
    void draw(SDL_Surface *window_surface);

private:
    Spritesheet    m_spritesheet;
    SDL_Rect       m_position;
    double         m_speed;
    double         m_x;
    double         m_y;
};


#endif //TESTSDL_METEORITE_H
