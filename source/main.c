#include <nds.h>
#include <stdio.h>

int main(void) {
	
    consoleDemoInit();
    printf("\nDino Run NDS\n");

    while(1)
        swiWaitForVBlank();	
}
