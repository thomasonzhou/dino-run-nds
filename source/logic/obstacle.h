#include "collidable.h"
#include "game_state.h"
#include <nds.h>
extern "C"{
    #include "../sound.h"
}

#define TILE_FLOOR 15

class Obstacle: public Collidable{
        void handle_collision(GameState* game_state);
    public:
        void paint_collidable();
        Obstacle(int x1, int y1, int x2, int y2);
};