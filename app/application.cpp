#include "application.h"


Application::Application()
{
    m_window = SDL_CreateWindow("The Ship Game !",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                680, 480,
                                0);

    m_window_surface = SDL_GetWindowSurface(m_window);
}

Application::~Application()
{
    SDL_FreeSurface(m_window_surface);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Application::loop()
{
    bool keep_window_open = true;
    while(keep_window_open)
    {
        while(SDL_PollEvent(&m_window_event) > 0)
        {
            m_ship.handle_events(m_window_event);
            m_ship2.handle_events(m_window_event);
            switch(m_window_event.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
            }
        }

        update(1.0/60.0);
        draw();
    }
}

void Application::update(double delta_time)
{
    m_ship.update(delta_time);
    m_ship2.update(delta_time);
}

void Application::draw()
{
    SDL_FillRect(m_window_surface, nullptr, SDL_MapRGB(m_window_surface->format, 0, 0, 0));

    m_ship.draw(m_window_surface);
    m_ship2.draw(m_window_surface);

    SDL_UpdateWindowSurface(m_window);
}

void Application::start() {
    loop();
}
