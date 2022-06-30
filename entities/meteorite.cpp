//
// Created by stagiairedit on 29/06/2022.
//

#include <ctime>
#include "meteorite.h"
#include "../app/application.h"

int ip = 0;
int k = 0;
bool secondrow = false;

Meteorite::Meteorite() : m_spritesheet("images/animated_asteroid2.png",2,16)
{
    srand(time(0));
    m_x = Application::getWindowWidth();
    m_y = rand() % 410 - 70;
    m_speed = (float) ((rand() % 10 - 5) + 10);
    m_position.x = 680;
    m_position.y = 240;
    m_position.w = Application::getWindowWidth() / 10;
    m_position.h = Application::getWindowWidth() / 10;
    m_spritesheet.select_sprite(0,0);
}

void Meteorite::update(double delta_time)
{
    m_spritesheet.select_sprite(ip,k);
    m_x -= (m_speed * delta_time);
    m_position.x = m_x;
    m_position.y = m_y;
    ip++;
    if(secondrow = true && ip == 16)
    {
        ip = 0;
        k = 0;
    }else if(ip>17)
    {
        k=1;
        secondrow = true;
    }
    if(m_x < -70)
    {
        m_x = 680;
        m_y = rand() % 480 - 70;
        m_speed = (float) ((rand() % 10 - 5) + 10);
    }
}

void Meteorite::draw(SDL_Surface *window_surface)
{
    m_spritesheet.draw_selected_sprite(window_surface, &m_position);
}