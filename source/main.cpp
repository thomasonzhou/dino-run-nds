// #define DEBUG_ON

extern "C" {
	#include <nds.h>
	#include <stdio.h>
	#include "graphics.h"
	#include "sound.h"
}
#include "logic/game_state.h"
#include "logic/physics.h"
#include "logic/level_generation.h"

# ifdef DEBUG_ON
void printState(GameState* game_state){
    printf("\nGameState: \n");
    printf("sprite_x: %d\n", game_state->sprite_x);
    printf("sprite_y: %d\n", game_state->sprite_y);
    printf("sprite_vy: %d\n", game_state->sprite_vy);
    printf("sprite_jumping: %d\n", game_state->sprite_jumping);
}
#endif

GameState game_state;
Level level = Level(&game_state);

int count = 0;
void physics_ISR() {
    update_physics(&game_state);
	#ifdef DEBUG_ON
	printState(&game_state);
	#endif
	count = (count + 1) % 9000;
	if(count % 5 == 0){
		level.check_all_collisions(&game_state);
	}
	if(count % 15 == 0){
		level.update_level();
	}
	if(count % 300 == 0 || count % 660 == 0){
		level.create_spike();
	}
	else if(count % 360 == 0){
		level.create_item();
	}
}

int main(void) {

	irqSet(IRQ_TIMER0, &physics_ISR);
    init_physics(&game_state); // A good starting position
    init_graphics_main(&game_state);
	#ifdef DEBUG_ON
    consoleDemoInit();
    printf("\nDino Run NDS\n"); 
	#else
	init_graphics_sub(&game_state);
	#endif

    init_sound();
	start_background_music();
	irqEnable(IRQ_TIMER0);

	int keys;
	touchPosition touch;

    while(1){
    	//Read held keys
    	scanKeys();
    	keys = keysHeld();
		touchRead(&touch);

		if(keys){
			game_state.game_status = RUNNING;
		}

		if((keys & KEY_LEFT)){
			if(game_state.sprite_x > 0){
				game_state.sprite_x -= MOVE_SPEED + SPEED_INCREASE * game_state.sprite_version;
				game_state.sprite_direction = LEFT;
			}
		}
		if((keys & KEY_RIGHT)){
			if(game_state.sprite_x + SPRITE_SIZE < 255){
				game_state.sprite_x += MOVE_SPEED + SPEED_INCREASE * game_state.sprite_version;
				game_state.sprite_direction = RIGHT;
			}
		}
    	if((keys & KEY_UP || keys & KEY_A) && (game_state.sprite_y  > 0)){
			jump(&game_state);
		}

		if(touch.px || touch.py){
			start_background_music();
		}

		update_graphics(&game_state);
    }
}
