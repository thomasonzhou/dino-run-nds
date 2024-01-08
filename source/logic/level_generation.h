#include "game_state.h"
#include "collidable.h"
#include "obstacle.h"
#include "collectable.h"
#include <deque>

extern "C"{
    #include "../graphics.h"
}

// use a deque to store dynamic levels

// initially hardcode the level (loop through a series of repeated collidables)
class Level{
    GameState* game_state;
    std::deque<Collidable*> collidables;
    void prune_collidables();
    void shift_all_collidables();
    void paint_all_collidables();
public:
    Level(GameState* game_state);
    void check_all_collisions(GameState* game_state);
    void create_spike();
    void create_item();
    void update_level();
};
