#include "game_state.h"
#include "collidable.h"
#include "obstacle.h"
#include <deque>

// use a deque to store dynamic levels

// initially hardcode the level (loop through a series of repeated collidables)
class Level{
    std::deque<Collidable*> collidables;
    public:
        void create_spike();
};

void init_level(GameState* game_state, Level* level);
void update_level();