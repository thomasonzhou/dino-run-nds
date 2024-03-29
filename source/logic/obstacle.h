#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "collidable.h"
#include "game_state.h"
#include <nds.h>
extern "C"{
    #include "../sound.h"
    #include "../graphics.h"
}

#define TILE_FLOOR 15

class Obstacle: public Collidable{
        int grace_immunity;
        void handle_collision(GameState* game_state);
    public:
        void paint_collidable();
        Obstacle(int x1, int y1, int x2, int y2);
};
#endif
