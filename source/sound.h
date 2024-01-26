#ifndef SOUND_H
#define SOUND_H

#include <nds.h>
#include <maxmod9.h>
#include "soundbank.h"
#include "soundbank_bin.h"

void init_sound();
void start_background_music();
void play_sound_hit_obstacle();
void play_sound_collect_item();
void play_sound_levelup();

#endif
