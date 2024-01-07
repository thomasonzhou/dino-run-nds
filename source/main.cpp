#include <cstdio>
extern "C" {
	#include <nds.h>
	#include <stdio.h>
	#include "graphics.h"
	#include "sound.h"
}
#include "logic/game_state.h"
#include "logic/physics.h"

void printState(GameState* game_state){
    printf("\nGameState: \n");
    printf("sprite_x: %d\n", game_state->sprite_x);
    printf("sprite_y: %d\n", game_state->sprite_y);
    printf("sprite_vy: %d\n", game_state->sprite_vy);
    printf("sprite_jumping: %d\n", game_state->sprite_jumping);
}

GameState game_state;

void physics_ISR() {
    update_physics(&game_state);
	printState(&game_state);
}

int main(void) {

	// irqInit();
	irqSet(IRQ_TIMER0, &physics_ISR);
    init_physics(&game_state); // A good starting position
    consoleDemoInit();
    init_graphics(&game_state);
    init_sound();

	irqEnable(IRQ_TIMER0);

    printf("\nDino Run NDS\n"); 

	int keys;

    while(1){
    	//Read held keys
    	scanKeys();
    	keys = keysHeld();

    	// if((keys & KEY_RIGHT) && (x < (SCREEN_WIDTH - SPRITE_WIDTH))) x+=2;
    	// if((keys & KEY_DOWN) && (y < (SCREEN_HEIGHT - SPRITE_HEIGHT))) y+=2;
    	// if((keys & KEY_LEFT) && (x  > 0)) x-=2;
    	if((keys & KEY_UP) && (game_state.sprite_y  > 0)){
			jump(&game_state);
			printf("\njump!");
		}
		// update_physics(&game_state);

		update_graphics(&game_state);
    }
}
