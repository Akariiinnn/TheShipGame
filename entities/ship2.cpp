#include "ship2.h"
#include "../app/application.h"

int const SPRITESHEET_UP = 0;
int const SPRITESHEET_LEFT = 1;
int const SPRITESHEET_RIGHT = 2;
int const SPRITESHEET_DOWN = 3;
float const SHIP_SPEED = 12.0;

//Ship2 class methods

Ship2::Ship2(): m_spritesheet("images/spritesheet.png", 1, 8)
{
    m_position.x = 100;
    m_position.y = 100;
    m_position.w = Application::getWindowWidth() / 16;
    m_position.h = Application::getWindowHeight() / 16;

    m_x = 0.0;
    m_y = 0.0;

    m_direction = Direction::NONE;

    m_spritesheet.select_sprite(0, 0);
}

void Ship2::handle_events(SDL_Event const &event)
{
    switch(event.type)
    {
        case SDL_KEYDOWN: {
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);

            if (keys[SDL_SCANCODE_UP] == 1) {
                m_direction = Direction::UP;
            }
            else if (keys[SDL_SCANCODE_DOWN] == 1) {
                m_direction = Direction::DOWN;
            }
            else if (keys[SDL_SCANCODE_LEFT] == 1) {
                m_direction = Direction::LEFT;
            }
            else if (keys[SDL_SCANCODE_RIGHT] == 1) {
                m_direction = Direction::RIGHT;
            }

            if (keys[SDL_SCANCODE_UP] == 1 && keys[SDL_SCANCODE_KP_ENTER] == 1) {
                m_direction = Direction::UPFIRING;
            }
            else if (keys[SDL_SCANCODE_DOWN] == 1 && keys[SDL_SCANCODE_KP_ENTER] == 1) {
                m_direction = Direction::DOWNFIRING;
            }
            else if (keys[SDL_SCANCODE_LEFT] == 1 && keys[SDL_SCANCODE_KP_ENTER] == 1) {
                m_direction = Direction::LEFTFIRING;
            }
            else if (keys[SDL_SCANCODE_RIGHT] == 1 && keys[SDL_SCANCODE_KP_ENTER] == 1) {
                m_direction = Direction::RIGHTFIRING;
            }
            else if (keys[SDL_SCANCODE_KP_ENTER] == 1) {
                m_direction = Direction::NONEFIRING;
            }
            break;
        }

        case SDL_KEYUP: {
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);

            if (keys[SDL_SCANCODE_W] == 0) {
                m_direction = Direction::NONE;
            }
            else if (keys[SDL_SCANCODE_S] == 0) {
                m_direction = Direction::NONE;
            }
            else if (keys[SDL_SCANCODE_A] == 0) {
                m_direction = Direction::NONE;
            }
            else if (keys[SDL_SCANCODE_D] == 0) {
                m_direction = Direction::NONE;
            }

            if (keys[SDL_SCANCODE_W] == 0 && keys[SDL_SCANCODE_X] == 0)
                m_direction = Direction::NONE;
            else if (keys[SDL_SCANCODE_S] == 0 && keys[SDL_SCANCODE_X] == 0)
                m_direction = Direction::NONE;
            else if (keys[SDL_SCANCODE_A] == 0 && keys[SDL_SCANCODE_X] == 0)
                m_direction = Direction::NONE;
            else if (keys[SDL_SCANCODE_D] == 0 && keys[SDL_SCANCODE_X] == 0)
                m_direction = Direction::NONE;

            break;
        }
    }
}

void Ship2::update(double delta_time)
{
    switch(m_direction)
    {
        case Direction::NONE:
            m_x += 0.0;
            m_y += 0.0;
            m_spritesheet.select_sprite(3, 0);
            break;
        case Direction::UP:
            m_y = m_y - (SHIP_SPEED * delta_time);
            m_spritesheet.select_sprite(0, 0);
            break;
        case Direction::DOWN:
            m_y = m_y + (SHIP_SPEED * delta_time);
            m_spritesheet.select_sprite(2, 0);
            break;
        case Direction::LEFT:
            m_x = m_x - (SHIP_SPEED * delta_time);
            m_spritesheet.select_sprite(1, 0);
            break;
        case Direction::RIGHT:
            m_x = m_x + (SHIP_SPEED * delta_time);
            m_spritesheet.select_sprite(3, 0);
            break;
        case Direction::UPFIRING:
            m_y = m_y - (SHIP_SPEED * delta_time);
            m_spritesheet.select_sprite(4, 0);
            break;
        case Direction::LEFTFIRING:
            m_x = m_x - (SHIP_SPEED * delta_time);
            m_spritesheet.select_sprite(5, 0);
            break;
        case Direction::DOWNFIRING:
            m_y = m_y + (SHIP_SPEED * delta_time);
            m_spritesheet.select_sprite(6, 0);
            break;
        case Direction::RIGHTFIRING:
            m_x = m_x + (SHIP_SPEED * delta_time);
            m_spritesheet.select_sprite(7, 0);
            break;
        case Direction::NONEFIRING:
            m_x += 0.0;
            m_y += 0.0;
            m_spritesheet.select_sprite(7,0);
            break;
    }
    m_position.x = m_x;
    m_position.y = m_y;

}

void Ship2::draw(SDL_Surface *window_surface)
{
    m_spritesheet.draw_selected_sprite(window_surface, &m_position);
}

SDL_Rect Ship2::getPosition() {
    return m_position;
}
