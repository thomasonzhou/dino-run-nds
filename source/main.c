#include <nds.h>
#include <stdio.h>
#include "graphics.h"
#include "sound.h"
#include "logic/game_state.h"

extern u16* gfx;

int main(void) {
	
    GameState game_state;
    game_state.sprite_x = 20;
    game_state.sprite_y = 100;
    consoleDemoInit();
    init_graphics(&game_state);
    init_sound();

    printf("\nDino Run NDS\n");

    int x = 20, y = 100, keys;

    while(1){
    	//Read held keys
    	scanKeys();
    	keys = keysHeld();

    	// if((keys & KEY_RIGHT) && (x < (SCREEN_WIDTH - SPRITE_WIDTH))) x+=2;
    	if((keys & KEY_DOWN) && (y < (SCREEN_HEIGHT - SPRITE_HEIGHT))) y+=2;
    	// if((keys & KEY_LEFT) && (x  > 0)) x-=2;
    	if((keys & KEY_UP) && (y  > 0)) y-=2;

    	oamSet(&oamMain, 	// oam handler
    		0,				// Number of sprite
    		x, y,			// Coordinates
    		0,				// Priority
    		0,				// Palette to use
    		SpriteSize_32x32,			// Sprite size
    		SpriteColorFormat_256Color,	// Color format
    		game_state.sprite_gfx,			// Loaded graphic to display
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
