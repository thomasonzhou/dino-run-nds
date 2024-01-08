#include "collidable.h"
#include "game_state.h"
#include <nds.h>

#define TILE_FLOOR 15

class Obstacle: public Collidable{
        void handle_collision(GameState* game_state);
        void paint_collidable();
    public:
        Obstacle(int x1, int y1, int x2, int y2);
};