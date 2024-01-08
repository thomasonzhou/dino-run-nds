#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include "game_state.h"

class Collidable{
protected:
    // tile coordinates, 8x8 pixels per tile, 32x24 tiles per screen 
    int x1;
    int y1;
    int x2;
    int y2;
    virtual void handle_collision(GameState* game_state) = 0;
public:
    Collidable(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {};
    void check_collision(GameState* game_state);
    virtual void paint_collidable() = 0;
    virtual ~Collidable() = default;
    int get_x2();
    void shift_left();
};
#endif