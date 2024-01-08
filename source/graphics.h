#include <nds.h>
#include "logic/game_state.h"

#define LIGHT_RED ARGB16(1, 15, 0, 0)
#define DARK_RED ARGB16(1, 5, 0, 0)
#define GRAY ARGB16(1, 10, 10, 10)

#define SCREEN_WIDTH	256
#define	SCREEN_HEIGHT	192

#define	SPRITE_WIDTH	32
#define	SPRITE_HEIGHT	32

void init_graphics_main(GameState* game_state);
void init_graphics_sub(GameState* game_state);
void update_graphics(GameState* game_state);

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
    0,0,0,0,0,0,0,1,
    0,0,0,0,0,0,1,1,
    0,0,0,0,0,1,1,1,
    0,0,0,0,1,1,1,1,
    0,0,0,1,1,1,1,1,
    0,0,1,1,1,1,1,1,
    0,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
};
