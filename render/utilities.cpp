//
// Created by stagiairedit on 24/06/2022.
//

#include "utilities.h"
#include <iostream>
#include <SDL_image.h>

//Utilities

SDL_Surface *load_pngjpg(char const *path)
{
    int flags = IMG_INIT_PNG | IMG_INIT_JPG;
    int initiated_flags = IMG_Init(flags);

    if((initiated_flags & flags) != flags)
    {
        std::cout << "Failed to initialize all image loaders\n";
        std::cout << "IMG Error: " << IMG_GetError() << "\n";
    }

    SDL_Surface *image_surface = IMG_Load(path);

    if(!image_surface)
    {
        std::cout << "Failed to open image\n";
        std::cout << "IMG Error: " << IMG_GetError() << "\n";
    }

    return(image_surface);
}

SDL_Surface *load_bmp(char const *path)
{
    SDL_Surface *image_surface = SDL_LoadBMP(path);

    if(!image_surface)
        return 0;

    return image_surface;
}