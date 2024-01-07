#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <nds.h>
#include <stdio.h>

typedef struct GameState {
    u16* sprite_gfx; 
    int sprite_x;
    int sprite_y; 

    int sprite_vy;
    int sprite_jumping;

    int game_started;
} GameState;

#endif