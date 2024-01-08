#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <nds.h>
#include "logic/game_state.h"

#define LIGHT_RED ARGB16(1, 15, 0, 0)
#define DARK_RED ARGB16(1, 5, 0, 0)
#define LIGHT_GRAY ARGB16(1, 25, 25, 25)
#define YELLOW ARGB16(1, 31, 27, 23)

#define SCREEN_WIDTH	256
#define	SCREEN_HEIGHT	192

#define	SPRITE_WIDTH	32
#define	SPRITE_HEIGHT	32

void init_graphics_main(GameState* game_state);
void init_graphics_sub(GameState* game_state);
void update_graphics(GameState* game_state);

void update_dino_sprite(GameState* game_state);

void clear_collidables();

const unsigned char empty_tile[64] = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
};
const unsigned char full_tile[64] = {
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
};

const unsigned char half_triangle_tile[64] = {
    0,0,0,0,0,0,0,2,
    0,0,0,0,0,0,2,2,
    0,0,0,0,0,2,2,2,
    0,0,0,0,2,2,2,2,
    0,0,0,2,2,2,2,2,
    0,0,2,2,2,2,2,2,
    0,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,
};

const unsigned char quarter_circle_tile[64] = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,3,
    0,0,0,0,0,3,3,3,
    0,0,0,0,3,3,3,3,
    0,0,0,0,3,3,3,3,
    0,0,0,3,3,3,3,3,
};

#endif