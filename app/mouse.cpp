//
// Created by stagiairedit on 04/07/2022.
//

#include "mouse.h"

Mouse::Mouse() : tex("../images/curseur.png",1,1)
{
    point.w = 1;
    point.h = 1;
    tex.select_sprite(0,0);
}

Mouse::~Mouse()
{
    //dtor
}

void Mouse::update() {
    buttons = SDL_GetMouseState(&this->x, &this->y);
    point.x = this->x;
    point.y = this->y;
}

void Mouse::draw(SDL_Surface *window_surface) {
    tex.draw_selected_sprite(window_surface, &point);
}

void Mouse::handle_events(const SDL_Event &event) {
    if((buttons & SDL_BUTTON_LMASK) != 0) SDL_Log("Mouse button 1 (left) is pressed.");
}
