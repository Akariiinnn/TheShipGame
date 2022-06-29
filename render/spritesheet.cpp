//
// Created by stagiairedit on 24/06/2022.
//

#include "spritesheet.h"

Spritesheet::Spritesheet(char const *path, int row, int column)
{
    m_spritesheet_image = load_pngjpg(path);
    m_clip.w = m_spritesheet_image->w / column;
    m_clip.h = m_spritesheet_image->h / row;
}

Spritesheet::~Spritesheet()
{
    SDL_FreeSurface(m_spritesheet_image);
}

void Spritesheet::select_sprite(int x, int y)
{
    m_clip.x = x * m_clip.w;
    m_clip.y = y * m_clip.h;
}

void Spritesheet::draw_selected_sprite(SDL_Surface *window_surface, SDL_Rect *position)
{
    SDL_BlitSurface(m_spritesheet_image, &m_clip, window_surface, position);
}