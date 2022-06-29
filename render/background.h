//
// Created by stagiairedit on 29/06/2022.
//

#ifndef TESTSDL_BACKGROUND_H
#define TESTSDL_BACKGROUND_H

#include <SDL.h>

class Background {
public:
    Background(int);
    ~Background() = default;

    void update(double delta_time);
    void draw(SDL_Surface *window_surface);

private:
    SDL_Surface   *m_background_image;
    SDL_Rect       m_position;
};


#endif //TESTSDL_BACKGROUND_H
