#include "graphics.h"
#include "007.h"

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

u16* gfx;

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

void init_dino_sprite(){
    VRAM_B_CR = VRAM_ENABLE | VRAM_B_MAIN_SPRITE_0x06400000;
    oamInit(&oamMain, SpriteMapping_1D_32, false);
    gfx = oamAllocateGfx(&oamMain, SpriteSize_32x32, SpriteColorFormat_256Color);
    swiCopy(_07Pal, SPRITE_PALETTE, _07PalLen/2);
    swiCopy(_07Tiles, gfx, _07TilesLen/2);

    int x = 0, y = 0, keys;

    while(1){
    	//Read held keys
    	scanKeys();
    	keys = keysHeld();

    	//Modify position of the sprite accordingly
    	if((keys & KEY_RIGHT) && (x < (SCREEN_WIDTH - SPRITE_WIDTH))) x+=2;
    	if((keys & KEY_DOWN) && (y < (SCREEN_HEIGHT - SPRITE_HEIGHT))) y+=2;
    	if((keys & KEY_LEFT) && (x  > 0)) x-=2;
    	if((keys & KEY_UP) && (y  > 0)) y-=2;

    	oamSet(&oamMain, 	// oam handler
    		0,				// Number of sprite
    		x, y,			// Coordinates
    		0,				// Priority
    		0,				// Palette to use
    		SpriteSize_32x32,			// Sprite size
    		SpriteColorFormat_256Color,	// Color format
    		gfx,			// Loaded graphic to display
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
}

void init_graphics(){

    init_red_background();
    init_dino_sprite();
}


