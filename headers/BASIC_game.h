#ifndef BASIC_GAME_H
#define BASIC_GAME_H

#include <cassert>

class Basic_Game
{
  public:
    enum State
    {
        OFF = 0,
        ON = 1
    };
    State state;
};

#endif