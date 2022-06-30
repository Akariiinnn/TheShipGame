//
// Created by stagiairedit on 24/06/2022.
//

#ifndef UNTITLED3_SPRITESHEET_H
#define UNTITLED3_SPRITESHEET_H

#include <SDL.h>
#include "utilities.h"

//Spritesheet class header

class Spritesheet
{
public:
    Spritesheet(char const *path, int row, int column);
    ~Spritesheet();

    void select_sprite(int x, int y);
    void draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *position);

private:
    SDL_Rect      m_clip;
    SDL_Surface  *m_spritesheet_image;

    int m_start_x;
    int m_start_y;
};
#endif //UNTITLED3_SPRITESHEET_H
