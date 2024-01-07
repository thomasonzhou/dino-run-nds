extern "C"{
    #include "game_state.h"
}
#define BASE_Y 100
#define BASE_X 20

#define JUMP_VELOCITY -10
#define GRAVITY 1


void init_physics(GameState* game_state);
void update_physics(GameState* game_state);
void jump(GameState* game_state);