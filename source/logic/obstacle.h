#include "collidable.h"

class Obstacle: public Collidable{
    public:
        Obstacle(int x1, int y1, int x2, int y2): Collidable(x1, y1, x2, y2){};
        void handle_collision() override{};
};