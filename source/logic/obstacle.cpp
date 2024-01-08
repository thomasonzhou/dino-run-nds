#include "obstacle.h"
#include "game_state.h"

void Obstacle::handle_collision(GameState* game_state){
    if(game_state->sprite_version > 1){
        game_state->sprite_version--;
        // update sprite
    } else {
        game_state->game_status = GAME_OVER;
    }
}

void::Obstacle::paint_collidable(){
    printf("painting obstacle\n");
}

Obstacle::Obstacle(int x1, int y1, int x2, int y2): Collidable(x1, y1, x2, y2){
    this->paint_collidable();
}