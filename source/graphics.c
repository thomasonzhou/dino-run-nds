#include "graphics.h"

const unsigned char empty_tile[] = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
};
const unsigned char full_tile[] = {
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,
};


void init_red_background(){

    REG_DISPCNT = MODE_5_2D | DISPLAY_BG1_ACTIVE;
    VRAM_A_CR = VRAM_ENABLE | VRAM_A_MAIN_BG;

    BGCTRL[1] = BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_32x32 | BG_COLOR_256;

    BG_PALETTE[0] = LIGHT_RED;
    BG_PALETTE[1] = DARK_RED;

    swiCopy(empty_tile, (u8*)BG_TILE_RAM(1), 64);
    swiCopy(full_tile, (u8*)BG_TILE_RAM(1) + 64, 64);

    for(int c = 0; c < 32; c++){
        for(int r = 0; r < 16; r++){
            BG_MAP_RAM(0)[r * 32 + c] = 0;
        }
        for(int r = 16; r < 24; r++){
            BG_MAP_RAM(0)[r * 32 + c] = 1;
        }
    }
}

void init_graphics(){

    init_red_background();
}


