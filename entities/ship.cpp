#include "ship.h"
#include "../app/application.h"

float const SHIP_SPEED = 12.0;

// Ship class methods

Ship::Ship(): m_spritesheet("images/spritesheet.png", 1, 8)
{
    m_position.x = 0;
    m_position.y = 0;
    m_position.w = Application::getWindowWidth() / 16;
    m_position.h = Application::getWindowHeight() / 16;

    m_x = 0.0;
    m_y = 0.0;

    m_direction = Direction::NONE;

    m_spritesheet.select_sprite(3, 0);
}

void Ship::handle_events(SDL_Event const &event)
{
    switch(event.type)
    {
        case SDL_KEYDOWN: {
            Uint8 const *keys = SDL_GetKeyboardState(nullptr);

            if(keys[SDL_SCANCODE_ESCAPE] == 1)
            {
                std::cout << "Exiting..." << "\n";
                SDL_Delay(3000);
                exit(0);
            }

            if (keys[SDL_SCANCODE_W] == 1) {
                m_direction = Direction::UP;
                m_orientation = Orientation::NORTH;
            }
            else if (keys[SDL_SCANCODE_S] == 1) {
                m_direction = Direction::DOWN;
                m_orientation = Orientation::SOUTH;
            }
            else if (keys[SDL_SCANCODE_A] == 1) {
                m_direction = Direction::LEFT;
                m_orientation = Orientation::WEST;
            }
            else if (keys[SDL_SCANCODE_D] == 1) {
                m_direction = Direction::RIGHT;
                m_orientation = Orientation::EAST;
            }

            if (keys[SDL_SCANCODE_W] == 1 && keys[SDL_SCANCODE_X] == 1) {
                m_direction = Direction::UPFIRING;
                m_orientation = Orientation::NORTH;
            }
            else if (keys[SDL_SCANCODE_S] == 1 && keys[SDL_SCANCODE_X] == 1) {
                m_direction = Direction::DOWNFIRING;
                m_orientation = Orientation::SOUTH;
            }
            else if (keys[SDL_SCANCODE_A] == 1 && keys[SDL_SCANCODE_X] == 1) {
                m_direction = Direction::LEFTFIRING;
                m_orientation = Orientation::WEST;
            }
            else if (keys[SDL_SCANCODE_D] == 1 && keys[SDL_SCANCODE_X] == 1) {
                m_direction = Direction::RIGHTFIRING;
                m_orientation = Orientation::EAST;
            }
            else if (keys[SDL_SCANCODE_X] == 1) {
                m_direction = Direction::NONEFIRING;
                m_orientation = Orientation::EAST;
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

void Ship::update(double delta_time)
{
    switch(m_direction)
    {
        case Direction::NONE:
            m_x += 0.0;
            m_y += 0.0;
            m_spritesheet.select_sprite(3, 0);
            m_orientation = Orientation::EAST;
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

void Ship::draw(SDL_Surface *window_surface)
{
    m_spritesheet.draw_selected_sprite(window_surface, &m_position);
}

SDL_Rect Ship::getPosition() {
    return m_position;
}

Ship::Orientation Ship::getOrientation() {
    return m_orientation;
}
