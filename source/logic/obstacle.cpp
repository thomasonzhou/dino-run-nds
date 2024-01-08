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
