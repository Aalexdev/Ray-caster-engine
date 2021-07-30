#include <iostream>
#include <RC-Engine.hpp>

void OnTick(const int delta){
    std::cout << "test" << std::endl;
}

int main(void){

    RC_Engine engine;

    engine.init();

    engine.set_Ontick(OnTick);
    engine.run();

    engine.quit();

};