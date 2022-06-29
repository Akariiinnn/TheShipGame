//
// Created by stagiairedit on 29/06/2022.
//

#include "background.h"
#include "utilities.h"

Background::Background(int x)
{
    m_background_image = load_pngjpg("images/fond.png");
    m_position.x = x;
    m_position.y = 0;
    m_position.w = 680;
    m_position.h = 480;
}

void Background::update(double delta_time) {
}

void Background::draw(SDL_Surface *window_surface) {
    SDL_BlitSurface(m_background_image, NULL, window_surface, &m_position);
}