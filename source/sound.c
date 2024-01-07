#include "sound.h"

void init_sound(){
    mmInitDefaultMem((mm_addr)soundbank_bin);
    mmLoad(MOD_4WTUDONE);
}

void start_background_music(){
    mmStart(MOD_4WTUDONE, MM_PLAY_LOOP);
}