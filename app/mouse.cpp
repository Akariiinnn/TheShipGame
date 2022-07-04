//
// Created by stagiairedit on 04/07/2022.
//

#include "mouse.h"

Mouse::Mouse() : tex("../images/curseur.png",1,1)
{
    rect.w = 25;
    rect.h = 25;
    point.w = 1;
    point.h = 1;
}

Mouse::~Mouse()
{
    //dtor
}

void Mouse::update() {
    SDL_GetMouseState(&this->x, &this->y);
    std::cout << "Mouse position : " << this->x << " " << this->y << std::endl;
}

void Mouse::draw(SDL_Surface *window_surface) {
    tex.draw_selected_sprite(window_surface, &point);
}
