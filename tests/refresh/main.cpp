#include <iostream>
#include <RCE-Engine.hpp>

class Game{
    public:
        Game();
        ~Game();

        void setup(void);
        void run(void);
        
        static void OnTick(const int delta);
    
    private:
        RC_Engine engine;
};

void Game::OnTick(const int delta){}

Game::Game(){
    engine.init();
}

void Game::setup(void){
    engine.set_Ontick(OnTick);
    engine.set_clear_color(0, 255, 255);
}

void Game::run(void){
    engine.run();
}

Game::~Game(){
    engine.quit();
}

int main(void){
    Game game;

    game.setup();
    game.run();
};
