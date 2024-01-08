#include "game_state.h"
#include "collidable.h"
#include <deque>
// use a deque to store dynamic levels

// initially hardcode the level (loop through a series of repeated collidables)

void init_level(GameState* game_state);
void update_level();

class Level{
    std::deque<Collidable*> collidables;
    public:
        void create_spike();
};