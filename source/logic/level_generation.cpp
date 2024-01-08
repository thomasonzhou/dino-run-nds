#include "level_generation.h"
#include "game_state.h"

Level::Level(GameState* game_state){
    game_state->game_status = MENU;
    this->game_state = game_state;
    this->create_spike();
}

void Level::create_spike(){
    this->collidables.push_back(new Obstacle(30, 15, 31, 15));
}

void Level::create_item(){
    this->collidables.push_back(new Collectable(30, 14, 31, 15));
}

void Level::prune_collidables(){

    while(this->collidables.size() > 0 && this->collidables[0]->get_x2() <= 1){
        delete this->collidables[0];
        this->collidables.pop_front();
    }
}

void Level::shift_all_collidables(){
    for(unsigned int i = 0; i < this->collidables.size(); i++){
        this->collidables[i]->shift_left();
    }
}

void Level::paint_all_collidables(){
    for(unsigned int i = 0; i < this->collidables.size(); i++){
        this->collidables[i]->paint_collidable();
    }
}

void Level::check_all_collisions(GameState* game_state){
    for(unsigned int i = 0; i < this->collidables.size(); i++){
        this->collidables[i]->check_collision(game_state);
    }
}

void Level::update_level(){
    clear_collidables();
    prune_collidables();
    shift_all_collidables();
    paint_all_collidables();
}