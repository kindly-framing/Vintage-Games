#ifndef BASIC_GAME_H
#define BASIC_GAME_H

class Basic_Game
{
  public:
    enum State
    {
        OFF,
        ON
    };
    State state;

    bool is_open() { return state; }
    bool close() { state == OFF; }
};

#endif