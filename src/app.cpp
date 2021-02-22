#include <iostream>
#include <SDL2/SDL.h>

#include "game.h"

int main(){
    Game game;
    game.Init("Stratego", 600, 600, 32);
    game.DrawBackground();
    while(game.Running()){
        game.DrawBackground();
        game.HandleEvents(&game);
        game.MouseHover();
        game.Update();
        game.Draw();
        game.testClass();
    }

    game.Clean();
    return 0;
}