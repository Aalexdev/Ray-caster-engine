#include "RCE-Color.hpp"
#include <SDL2/SDL.h>
#include <sstream>

using namespace RCE;

static inline void convert_hexa_to_Uint32(std::string hex_src, Uint32 *dst){
    std::stringstream ss;
    ss << std::hex << hex_src;
    ss >> *dst;
    std::cout << hex_src << " : 0x" << std::hex << *dst << std::endl;
}

Color::Color(){
    set_rgba(0, 0, 0, 0);
}

Color::Color(unsigned char r, unsigned char g, unsigned char b){
    set_rgb(r, g, b);
}

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a){
    set_rgba(r, g, b, a);
}

Color::~Color(){

}

unsigned char Color::red(void) const{
    return r;
}

unsigned char Color::green(void) const{
    return g;
}

unsigned char Color::blue(void) const{
    return b;
}

unsigned char Color::alpha(void) const{
    return a;
}

void Color::set_rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a){
    set_red(r);
    set_green(g);
    set_blue(b);
    set_alpha(a);
}

void Color::set_rgb(unsigned char r, unsigned char g, unsigned char b){
    set_red(r);
    set_green(g);
    set_blue(b);
}

void Color::set_red(unsigned char red){
    r = red;
}

void Color::set_green(unsigned char green){
    g = green;
}

void Color::set_blue(unsigned char blue){
    b = blue;
}

void Color::set_alpha(unsigned char alpha){
    a = alpha;
}