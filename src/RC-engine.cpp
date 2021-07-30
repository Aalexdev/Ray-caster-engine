#include "RC-engine.hpp"

// sdl
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_gpu.h>

#define __func__ __FUNCTION__

// libs init flags
#define IMG_INIT_FLAGS IMG_INIT_JPG | IMG_INIT_PNG
#define MIX_INIT_FLAGS MIX_INIT_OGG | MIX_INIT_MP3
#define SDL_CREATEWINDOW_FLAGS SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE

// macros
#define ERR(error, reason, type) \
    RCE::Error err(__func__, error, reason, type); \
    this->errors.push_back(err); \
                                \
    if (this->dbg_level > 0){ \
        err.print(std::cerr); \
    }

#define to_window (SDL_Window*)
#define to_target (GPU_Target*)

using namespace RCE;

/* -- Error class -- */

Error::Error(){
    _function = "unlnown";
    _error = "none";
    _reason = "none";
    _type = err::ERR_invalid_error; 
}

Error::Error(std::string function, std::string error, std::string reason, err::Type type){
    _function = function;
    _error = error;
    _reason = reason;
    _type = type;
}

Error::~Error(){}

const std::string Error::function(void) const{
    return _function;
}

const std::string Error::func(void) const{
    return function();
}

const std::string Error::error(void) const{
    return _error;
}

const std::string Error::err(void) const{
    return error();
}

const std::string Error::reason(void) const{
    return _reason;
}

const std::string Error::what(void) const{
    return reason();
}

const std::string Error::why(void) const{
    return reason();
}

const err::Type Error::type(void) const{
    return _type;
}

void Error::print(std::ostream &stream) const{
    stream << "ERROR :: in \"" << function() << "\" : error id : " << type() << std::endl;
    stream << "\t" << error() << " : " << reason() << std::endl;
    stream << std::endl;
}

/* -- end of the Error class -- */

RC_Engine::RC_Engine(){
    reset_init();
}

RC_Engine::~RC_Engine(){
    quit();
}

bool RC_Engine::init_SDL2_ttf(void){
    if (TTF_Init() != -1){
        ERR("TTF_Init", TTF_GetError(), err::ERR_SDL2_ttf_init);
        return false;
    }
    is_ttf_init = true;
    return true;
}

bool RC_Engine::init_SDL2_image(void){
    if (IMG_Init(IMG_INIT_FLAGS) != IMG_INIT_FLAGS){
        ERR("IMG_Init", IMG_GetError(), err::ERR_SDL2_image_init);
        return false;
    }
    is_image_init = true;
    return true;
}

bool RC_Engine::init_SDL2_mixer(void){
    if (Mix_Init(MIX_INIT_FLAGS) != MIX_INIT_FLAGS){
        ERR("Mix_Init", Mix_GetError(), err::ERR_SDL2_mixer_init);
        return false;
    }
    is_mixer_init = true;
    return true;
}

bool RC_Engine::init_SDL2_gpu(void){
    if (!window) return false;
    target = (void*)GPU_Init(1080, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    if (!target){
        auto error = GPU_PopErrorCode();
        ERR(error.function, GPU_GetErrorString(error.error), err::ERR_SDL2_gpu_init);
    }
    is_gpu_init = true;
    return true;
}


bool RC_Engine::init_SDL2_window(void){
    if (window) return true;
    window = (void*)SDL_CreateWindow("Ray caster", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_CREATEWINDOW_FLAGS);

    if (!window){
        ERR("SDL_CreateWindow", SDL_GetError(), err::ERR_SDL2_window_init);
        return false;
    }
    is_window_init = true;
    GPU_SetInitWindow(SDL_GetWindowID(to_window window));
    return true;
}

void RC_Engine::quit_SDL2_ttf(void){
    if (is_ttf_init){
        TTF_Quit();
    }
}

void RC_Engine::quit_SDL2_image(void){
    if (is_image_init){
        IMG_Quit();
    }
}

void RC_Engine::quit_SDL2_mixer(void){
    if (is_mixer_init){
        Mix_Quit();
    }
}

void RC_Engine::quit_SDL2_gpu(void){
    if (is_gpu_init){
        destroy_target();
        GPU_Quit();
    }
}

void RC_Engine::quit_SDL2(void){
    if (is_window_init){
        destroy_window();
    }

}

void RC_Engine::reset_init(void){
    is_ttf_init = false;
    is_image_init = false;
    is_mixer_init = false;
    is_gpu_init = false;
    is_window_init = false;
}

void RC_Engine::destroy_target(void){
    if (target){
        GPU_FreeTarget(to_target target);
        target = nullptr;
    }
}

void RC_Engine::destroy_window(void){
    if (window){
        SDL_DestroyWindow(to_window window);
        window = nullptr;
    }
}

bool RC_Engine::init(void){
    if (!init_SDL2_window()) return false;
    if (!init_SDL2_gpu()) return false;
    if (!init_SDL2_image()) return false;
    if (!init_SDL2_mixer()) return false;
    if (!init_SDL2_ttf()) return false;
    return true;
}

void RC_Engine::quit(void){
    quit_SDL2_gpu();
    quit_SDL2_image();
    quit_SDL2_mixer();
    quit_SDL2_ttf();
    quit_SDL2();
}