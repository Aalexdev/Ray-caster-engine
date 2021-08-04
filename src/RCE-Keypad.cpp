#include "RCE-Keypad.hpp"
#include <SDL2/SDL.h>

#define to_event (SDL_Event*)

using namespace RCE::events;

Keypad::Keypad(){
    for (int i=0; i<NUM_KEY; i++){
        push[i] = false;
        up[i] = true;
        down[i] = false;
    }
}

Keypad::~Keypad(){}

void Keypad::OnEvent(void *e){
    SDL_Event* event = to_event e;

    switch (event->type){
        case SDL_KEYDOWN:
            push[event->key.keysym.scancode] = true;
            down[event->key.keysym.scancode] = true;
            break;
        
        case SDL_KEYUP:
            up[event->key.keysym.scancode] = true;
            down[event->key.keysym.scancode] = false;
            break;
        
        default:
            break;
    }
}

void Keypad::OnTick(){
    for (int i=0; i<NUM_KEY; i++){
        push[i] = false;
        up[i] = false;
    }
}

bool Keypad::is_key_down(Key key){
    return down[key];
}

bool Keypad::is_key_up(Key key){
    return up[key];
}

bool Keypad::is_key_pushed(Key key){
    return push[key];
}
