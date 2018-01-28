#include "core.hpp"

class Timer {
public:
    Timer();
    void start();
    void stop();
    void pause();
    void unpause();
    void toggle();
    int get_ticks();
    bool is_started();
    bool is_paused();

private:
    int start_ticks;
    int paused_ticks;
    bool paused;
    bool started;
};
