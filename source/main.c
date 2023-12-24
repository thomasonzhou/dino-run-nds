#include <nds.h>
#include <stdio.h>
#include "graphics.h"
#include "sound.h"

int main(void) {
	
    consoleDemoInit();
    init_graphics();
    init_sound();

    printf("\nDino Run NDS\n");

    while(1)
        swiWaitForVBlank();	
}
