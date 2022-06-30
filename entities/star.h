//
// Created by stagiairedit on 30/06/2022.
//

#ifndef TESTSDL_STAR_H
#define TESTSDL_STAR_H
#include <SDL.H>
#include "../render/spritesheet.h"

class Star {
public:
    Star();
    ~Star() = default;

    SDL_Rect getPosition();

    void update(double delta_time);
    void draw(SDL_Surface *window_surface);

private:
    Spritesheet    m_spritesheet;
    SDL_Rect       m_position;
    double         m_x;
    double         m_y;
};


#endif //TESTSDL_STAR_H
