#include "graphics.h"
#include "dino1.h"

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

    REG_DISPCNT = MODE_3_2D | DISPLAY_BG1_ACTIVE;
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

void init_dino_sprite(GameState* game_state){
    VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE_0x06400000;
    oamInit(&oamMain, SpriteMapping_1D_32, false);
    game_state->sprite_gfx = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
    swiCopy(dino1Pal, SPRITE_PALETTE, dino1PalLen/2);
    swiCopy(dino1Tiles, game_state->sprite_gfx, dino1TilesLen/2);

}

void init_graphics(GameState* game_state){

    init_red_background();
    init_dino_sprite(game_state);
}

void update_graphics(GameState *game_state){
    oamSet(&oamMain, 	// oam handler
    0,				// Number of sprite
    game_state->sprite_x, game_state->sprite_y, // Coordinates
    0,				// Priority
    0,				// Palette to use
    SpriteSize_32x32,			// Sprite size
    SpriteColorFormat_256Color,	// Color format
    game_state->sprite_gfx,			// Loaded graphic to display
    -1,				// Affine rotation to use (-1 none)
    false,			// Double size if rotating
    false,			// Hide this sprite
    false, false,	// Horizontal or vertical flip
    false			// Mosaic
    );
    swiWaitForVBlank();
    //Update the sprites
    oamUpdate(&oamMain);
}


