#include "collidable.h"
#include "game_state.h"
extern "C"{
    #include "../sound.h"
}

#define TILE_FLOOR 15
class Collectable: public Collidable{
        bool collected;
        void handle_collision(GameState* game_state);
    public:
        void paint_collidable();
        Collectable(int x1, int y1, int x2, int y2);
};