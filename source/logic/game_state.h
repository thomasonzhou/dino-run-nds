#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <nds.h>
#include <stdio.h>

#define SPRITE_SIZE 32
#define SPEED_INCREASE 1
#define JUMP_INCREASE 1

enum DIRECTION{
    LEFT,
    RIGHT
};

enum GAME_STATUS{
    MENU,
    RUNNING,
    GAME_OVER
};

typedef struct GameState {

    u16* sprite_gfx; 
    int sprite_version;
    int items_collected;
    
    int sprite_x;
    int sprite_y; 

    int sprite_vy;
    int sprite_jumping;

    enum DIRECTION sprite_direction;
    enum GAME_STATUS game_status;
} GameState;

#endif