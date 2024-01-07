#include <nds.h>
#include "logic/game_state.h"

#define LIGHT_RED ARGB16(1, 15, 0, 0)
#define DARK_RED ARGB16(1, 5, 0, 0)

#define SCREEN_WIDTH	256
#define	SCREEN_HEIGHT	192

#define	SPRITE_WIDTH	32
#define	SPRITE_HEIGHT	32

void init_graphics(GameState* game_state);

void update_graphics(GameState* game_state);
