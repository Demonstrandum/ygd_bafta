#include "timer.hpp"

Timer::Timer()
{
    this->start_ticks = 0;
    this->paused_ticks = 0;
    this->paused = false;
    this->started = false;
}

void Timer::start()
{
    this->started = true;
    this->paused = false;
    this->start_ticks = SDL_GetTicks();
}

void Timer::stop()
{
    this->started = false;
    this->paused = false;
}

int Timer::get_ticks()
{
    if (this->started) {
        if(this->paused) return this->paused_ticks;
        else return SDL_GetTicks() - this->start_ticks;
    }
    return 0;
}

void Timer::pause()
{
    if (this->started && !this->paused) {
        paused = true;
        this->paused_ticks = SDL_GetTicks() - this->start_ticks;
    }
}

void Timer::unpause()
{
    if (this->paused) {
        this->paused = false;
        this->start_ticks = SDL_GetTicks() - this->paused_ticks;
        this->paused_ticks = 0;
    }
}

void Timer::toggle()
{ if (this->paused) this->unpause(); else this->pause(); }

bool Timer::is_started()
{ return started; }

bool Timer::is_paused()
{ return paused; }
