#include "obstacle.h"
#include "game_state.h"

void Obstacle::handle_collision(GameState* game_state){
    if(this->grace_immunity){
        this->grace_immunity--;
        return;
    } 
    play_sound_hit_obstacle();
    if(game_state->sprite_version > 1){
        game_state->sprite_version--;
        update_dino_sprite(game_state);
        // update sprite
    } else if(game_state->items_collected > 0){
        game_state->items_collected--;
    } else {
        game_state->items_collected = 0;
        game_state->game_status = GAME_OVER;
        printf("GAME OVER\n");
        // game over unhandled for now, friendly game
    }
    this->grace_immunity = 10;
}

void::Obstacle::paint_collidable(){
    // printf("painting obstacle\n");
    BG_MAP_RAM(1)[this->y1*32 + this->x1] = 1;
    BG_MAP_RAM(1)[this->y2*32 + this->x2] = 1 | (1<<10);
}

Obstacle::Obstacle(int x1, int y1, int x2, int y2): Collidable(x1, TILE_FLOOR, x2, TILE_FLOOR){
    this->paint_collidable();
    this->grace_immunity = 0;
}
