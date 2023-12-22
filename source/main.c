#include <nds.h>
#include <stdio.h>
#include "graphics.h"

int main(void) {
	
    consoleDemoInit();
    init_graphics();

    printf("\nDino Run NDS\n");

    while(1)
        swiWaitForVBlank();	
}
