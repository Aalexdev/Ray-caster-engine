#include <iostream>
#include <RC-Engine.hpp>


class Game{
    public:
        Game();
        ~Game();
        
        static void OnTick(const int delta);
    
    private:
        RC_Engine engine;
};

void Game::OnTick(const int delta){

}


Game::Game(){
    engine.init();
    engine.set_Ontick(OnTick);
    engine.run();
}

Game::~Game(){
    engine.quit();
}

int main(void){

    Game game;
};