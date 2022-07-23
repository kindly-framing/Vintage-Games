#ifndef MAIN_H_
#define MAIN_H_

#include "../headers/menu.h"
#include <vector>
// Add new games options here!
std::vector<Menu_Option> games = {{1, "Acey Ducey", play_acey_ducey}};

// Add play functions for each game here!
void play_acey_ducey();

#endif
