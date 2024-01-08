#include "collidable.h"
#include "game_state.h"

class Collectable: public Collidable{
    void handle_collision(GameState* game_state);
public:
    Collectable(int x1, int y1, int x2, int y2): Collidable(x1, y1, x2, y2){};
};