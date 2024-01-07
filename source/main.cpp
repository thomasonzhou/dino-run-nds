// #define DEBUG_ON

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
	#ifdef DEBUG_ON
	printState(&game_state);
	#endif
}

int main(void) {

	// irqInit();
	irqSet(IRQ_TIMER0, &physics_ISR);
    init_physics(&game_state); // A good starting position
	#ifdef DEBUG_ON
    consoleDemoInit();
	#endif
    init_graphics(&game_state);
    init_sound();

	irqEnable(IRQ_TIMER0);

    printf("\nDino Run NDS\n"); 

	int keys;

    while(1){
    	//Read held keys
    	scanKeys();
    	keys = keysHeld();

    	if((keys & KEY_UP || keys & KEY_A) && (game_state.sprite_y  > 0)){
			jump(&game_state);
			printf("\njump!");
		}

		update_graphics(&game_state);
    }
}
