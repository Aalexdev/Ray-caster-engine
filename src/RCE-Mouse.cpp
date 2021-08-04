#include "RCE-Mouse.hpp"
#include <SDL2/SDL.h>

#define to_event (SDL_Event *)

using namespace RCE::events;

Mouse::Mouse(){

}

Mouse::~Mouse(){

}

bool Mouse::is_btn_pushed(Button_enum button){
    switch (button){
        case BTN_LEFT:
            return pushed.left;
        
        case BTN_MIDDLE:
            return pushed.middle;
        
        case BTN_RIGHT:
            return pushed.right;
        
        default:
            return false;
    }
}

bool Mouse::is_btn_down(Button_enum button){
    switch (button){
        case BTN_LEFT:
            return down.left;
        
        case BTN_MIDDLE:
            return down.middle;
        
        case BTN_RIGHT:
            return down.right;
        
        default:
            return false;
    }
}

bool Mouse::is_btn_up(Button_enum button){
    switch (button){
        case BTN_LEFT:
            return up.left;
        
        case BTN_MIDDLE:
            return up.middle;
        
        case BTN_RIGHT:
            return up.right;
        
        default:
            return false;
    }
}

const int Mouse::get_x(void){
    return x;
}

const int Mouse::get_y(void){
    return y;
}

void Mouse::get_pos(int *x, int *y){
    *x = get_x();
    *y = get_y();
}

void Mouse::OnEvent(void *e){
    SDL_Event *event = to_event e;

    switch (event->type){
        case SDL_MOUSEBUTTONDOWN:
            switch (event->button.button){
                case SDL_BUTTON_LEFT:
                    pushed.left = true;
                    down.left = true;
                    break;
                
                case SDL_BUTTON_RIGHT:
                    pushed.right = true;
                    down.right = true;
                    break;
                
                case SDL_BUTTON_MIDDLE:
                    pushed.middle = true;
                    down.middle = true;
                    break;
                
                default:
                    break;
            }
            break;
        
        case SDL_MOUSEBUTTONUP:
            switch (event->button.button){
                case SDL_BUTTON_LEFT:
                    up.left = true;
                    down.left = false;
                    break;
                
                case SDL_BUTTON_MIDDLE:
                    up.middle = true;
                    down.middle = false;
                    break;
                
                case SDL_BUTTON_RIGHT:
                    up.right = true;
                    down.right = false;
                    break;
                
                default:
                    break;
            }
            break;
        
        case SDL_MOUSEMOTION:
            x = event->motion.x;
            y = event->motion.y;
            break;
        
        case SDL_MOUSEWHEEL:

            if(event->wheel.y > 0){
                wheel_up = true;

            } else if(event->wheel.y < 0){
                wheel_down = true;

            }
            break;
        
        default:
            break;
    }
}

void Mouse::OnTick(void){
    up = {false, false, false};
    pushed = {false, false, false};
    wheel_down = false;
    wheel_up = false;
}