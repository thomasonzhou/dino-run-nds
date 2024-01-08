#include "graphics.h"
#include "dino1.h"
#include "dino2.h"
#include "dino3.h"
#include "logic/game_state.h"

void init_background_main(){

    REG_DISPCNT = MODE_3_2D | DISPLAY_BG1_ACTIVE | DISPLAY_BG2_ACTIVE;
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

    BGCTRL[2] = BG_MAP_BASE(1) | BG_TILE_BASE(2) | BG_32x32 | BG_COLOR_256;
    BG_PALETTE[2] = LIGHT_GRAY;

    swiCopy(half_triangle_tile, (u8*)BG_TILE_RAM(2) + 64, 64);
    BG_MAP_RAM(1)[0] = 1;
    BG_MAP_RAM(1)[1] = 1 | (1<<10);
}

void init_dino_sprite(GameState* game_state){
    VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE_0x06400000;
    oamInit(&oamMain, SpriteMapping_1D_32, false);
    game_state->sprite_gfx = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
    swiCopy(dino1Pal, SPRITE_PALETTE, dino1PalLen/2);
    swiCopy(dino1Tiles, game_state->sprite_gfx, dino1TilesLen/2);

    game_state->sprite_version = 1;
}

void init_graphics_main(GameState* game_state){
    init_background_main();
    init_dino_sprite(game_state);
    // REG_POWERCNT ^= POWER_SWAP_LCDS;
}

void init_graphics_sub(GameState *game_state){
    REG_DISPCNT_SUB = MODE_0_2D | DISPLAY_BG0_ACTIVE;
    VRAM_C_CR = VRAM_ENABLE | VRAM_C_SUB_BG;

    BGCTRL_SUB[0] = BG_MAP_BASE(0) | BG_TILE_BASE(1) | BG_32x32 | BG_COLOR_256;

    BG_PALETTE_SUB[0] = DARK_RED;

    swiCopy(empty_tile, (u8*)BG_TILE_RAM_SUB(1), 64);

   
}

void update_sprite_graphics(GameState *game_state){
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
    (game_state->sprite_direction) == LEFT, false,	// Horizontal or vertical flip
    false			// Mosaic
    );
    swiWaitForVBlank();
    //Update the sprites
    oamUpdate(&oamMain);
}

void update_graphics(GameState *game_state){
    update_sprite_graphics(game_state);
}


