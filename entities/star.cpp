//
// Created by stagiairedit on 30/06/2022.
//

#include "star.h"
#include "../app/application.h"

Star::Star() : m_spritesheet("images/crystalgem32.png",4,4)
{
    m_x = rand();
}