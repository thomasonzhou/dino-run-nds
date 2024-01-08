#include "game_state.h"

class Collidable{
protected:
    int x1;
    int y1;
    int x2;
    int y2;
    virtual void handle_collision();
public:
    Collidable(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {};
    void check_collision(GameState* game_state){
        //sprite location is top left corner
        int sprite_x1 = game_state->sprite_x;
        int sprite_y1 = game_state->sprite_y;
        //bottom right corner
        int sprite_x2 = game_state->sprite_x + game_state->SPRITE_SIZE;
        int sprite_y2 = game_state->sprite_y + game_state->SPRITE_SIZE;

        if(x1 < sprite_x1 && sprite_x1 < x2 || x1 < sprite_x2 && sprite_x2 < x2){
            if(y1 < sprite_y1 && sprite_y1 < y2 || y1 < sprite_y2 && sprite_y2 < y2){
                handle_collision();
            }
        }
    }
};