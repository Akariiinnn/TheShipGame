//
// Created by stagiairedit on 04/07/2022.
//

#ifndef TESTSDL_MOUSE_H
#define TESTSDL_MOUSE_H


#include <SDL.h>
#include <iostream>
#include "../render/utilities.h"
#include "../render/spritesheet.h"

class Mouse {
public:
    Mouse();
    ~Mouse();
    void update();
    void draw(SDL_Surface *window_surface);
    Spritesheet tex;
    SDL_Rect point;
    Uint32 buttons;
    void handle_events(SDL_Event const &event);
    int x;
    int y;
};


#endif //TESTSDL_MOUSE_H
