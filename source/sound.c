#include "sound.h"

void init_sound(){
    mmInitDefaultMem((mm_addr)soundbank_bin);
    mmLoad(MOD_4WTUDONE);
    mmLoadEffect(SFX_CLANG);
    mmLoadEffect(SFX_CLICK);
    mmLoadEffect(SFX_SHARPEN);
}

void start_background_music(){
    mmStart(MOD_4WTUDONE, MM_PLAY_LOOP);
}

void play_sound_hit_obstacle(){
    mmEffect(SFX_CLANG);
}

void play_sound_collect_item(){
    mmEffect(SFX_CLICK);
}

void play_sound_levelup(){
    mmEffect(SFX_SHARPEN);
}
