#include <iostream>
#include <SDL2/SDL.h>

#include "Game.h"

int main(){
    GameInst::Instance()->Init("Stratego", 600, 600, 32);
    GameInst::Instance()->DrawBackground();
    while(GameInst::Instance()->Running()){
        GameInst::Instance()->DrawBackground();
        GameInst::Instance()->HandleEvents();
        GameInst::Instance()->MouseHover();
        GameInst::Instance()->Update();
        GameInst::Instance()->Draw();
        GameInst::Instance()->testClass();
    }

    GameInst::Instance()->Clean();
    return 0;
}