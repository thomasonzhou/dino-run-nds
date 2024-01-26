#include "physics.h"
#include "game_state.h"

void init_physics(GameState* game_state) {
    game_state->sprite_x = BASE_X;
    game_state->sprite_y = BASE_Y;
    game_state->sprite_vy = 0;
    game_state->sprite_jumping = 0;
    game_state->sprite_direction = RIGHT;

    TIMER_DATA(0) = TIMER_FREQ_1024(60);
    TIMER_CR(0) = TIMER_ENABLE | TIMER_DIV_1024 | TIMER_IRQ_REQ;
}

void fix_clipping(GameState* game_state) {
    if (game_state->sprite_y > 100 || game_state->sprite_y < 0) {
        game_state->sprite_y = 100;
        game_state->sprite_jumping = 0;
    }
}

void check_collisions(GameState* game_state) {
    
}

void update_physics(GameState* game_state) {
    game_state->sprite_y += game_state->sprite_vy;
    if(game_state->sprite_y < BASE_Y){
        game_state->sprite_vy += GRAVITY;
    }
    fix_clipping(game_state);
}

void jump(GameState* game_state) {
    if (game_state->sprite_jumping) return;
    game_state->sprite_jumping = 1;
    game_state->sprite_vy = JUMP_VELOCITY - game_state->sprite_version*JUMP_INCREASE;
}
