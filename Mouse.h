//
// Created by stagiairedit on 24/06/2022.
//

#ifndef UNTITLED3_MOUSE_H
#define UNTITLED3_MOUSE_H
#include "application.h"
#include <SDL.h>
#include <SDL_image.h>

/*class Mouse{   //unused class for now
public:
    SDL_Texture *tex;
    SDL_Rect rect;
    SDL_Rect point;
    Application app;
    void setApp(Application);
    SDL_Renderer *ren = app.getRenderer();

    Mouse() {
        tex = IMG_LoadTexture(ren,"images/curseur.png");
        rect.w = 25;
        rect.h = 25;
        point.w = 1;
        point.h = 1;
        SDL_ShowCursor(false);
    }

    void update() {
        SDL_GetMouseState(&rect.x, &rect.y);
        point.x = rect.x;
        point.y = rect.y;

    }

    void draw() {
        SDL_RenderCopy(ren, tex, NULL, &rect);

    }

}

*/
#endif //UNTITLED3_MOUSE_H
