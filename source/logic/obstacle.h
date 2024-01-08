#include "collidable.h"
#include "game_state.h"

class Obstacle: public Collidable{
        void handle_collision(GameState* game_state);
    public:
        Obstacle(int x1, int y1, int x2, int y2): Collidable(x1, y1, x2, y2){};
};