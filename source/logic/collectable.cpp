#include "collectable.h"
#include "game_state.h"

void Collectable::handle_collision(GameState* game_state){
    if(this->collected == false){
        play_sound_collect_item();
        game_state->items_collected++;
        this->collected = true;

        if(game_state->items_collected == 3){
            if(game_state->sprite_version < 3){
                play_sound_levelup();
                game_state->sprite_version++;
                update_dino_sprite(game_state);
                game_state->items_collected = 0;
            }
        }
    }
}

void::Collectable::paint_collidable(){
    // printf("painting obstacle\n");
    if (this->collected) return;
    BG_MAP_RAM(1)[this->y1*32 + this->x1] = 2;
    BG_MAP_RAM(1)[this->y1*32 + this->x2] = 2 | (1<<10);
    BG_MAP_RAM(1)[this->y2*32 + this->x1] = 2 | (1<<11);
    BG_MAP_RAM(1)[this->y2*32 + this->x2] = 2 | (1<<10) | (1<<11);
}

Collectable::Collectable(int x1, int y1, int x2, int y2): Collidable(x1, y1, x2, y2){
    this->paint_collidable();
    this->collected = false;
}
