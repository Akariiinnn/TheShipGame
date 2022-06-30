//
// Created by stagiairedit on 29/06/2022.
//

#include "background.h"
#include "utilities.h"
#include "../app/application.h"

Background::Background(int x)
{
    m_background_image = load_pngjpg("images/fond.png");
    m_position.x = x;
    m_position.y = 0;
    m_position.w = Application::getWindowWidth();
    m_position.h = Application::getWindowWidth();
}

void Background::update(double delta_time) {
}

void Background::draw(SDL_Surface *window_surface) {
    SDL_BlitSurface(m_background_image, NULL, window_surface, &m_position);
}