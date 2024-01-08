#include "collidable.h"
#define SPRITE_COLLISION_OFFSET 6

void Collidable::check_collision(GameState *game_state){
    //sprite location is top left corner
    const int sprite_x1 = game_state->sprite_x;
    const int sprite_y1 = game_state->sprite_y;

    //bottom right corner
    const int sprite_x2 = game_state->sprite_x + SPRITE_SIZE;
    const int sprite_y2 = game_state->sprite_y + SPRITE_SIZE - SPRITE_COLLISION_OFFSET;
    // printf("sprite_x1: %d\n sprite_y1: %d\n sprite_x2: %d\n sprite_y2: %d\n", sprite_x1, sprite_y1, sprite_x2, sprite_y2);

    const int tile_x1 = ((x1 % 32) * 8);
    const int tile_y1 = ((y1 % 24) * 8);

    const int tile_x2 = ((x2 % 32) * 8) + 7;
    const int tile_y2 = ((y2 % 24) * 8) + 7;

    // printf("tile_x1: %d\n tile_y1: %d\n tile_x2: %d\n tile_y2: %d\n", tile_x1, tile_y1, tile_x2, tile_y2);

    if((tile_x1 < sprite_x1 && sprite_x1 < tile_x2) || (tile_x1 < sprite_x2 && sprite_x2 < tile_x2)){
        if((tile_y1 < sprite_y1 && sprite_y1 < tile_y2) || (tile_y1 < sprite_y2 && sprite_y2 < tile_y2)){
            handle_collision(game_state);
            printf("collision\n");
        }
    }
}

int Collidable::get_x2(){
    return x2;
}

void Collidable::shift_left(){
    x1--;
    x2--;
}
