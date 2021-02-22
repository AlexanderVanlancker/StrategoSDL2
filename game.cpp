#include "game.h"
#include <string>

Game::Game(){

}

void Game::Init(const char* title, int width, int height, int bpp){
    int flags = 0;
	
	// initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }
    TTF_Init();

    window = SDL_CreateWindow("Definatly not tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED ,width, height, SDL_WINDOW_OPENGL);
    CHECK_ERROR(window == NULL, SDL_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    CHECK_ERROR(renderer == NULL, SDL_GetError());

	running = true;
	printf("Game Initialised Succesfully\n");

    font = TTF_OpenFont("OpenSans.ttf", 24); //this opens a font style and sets a size
    if (font == NULL) {
        fprintf(stderr, "error: font not found\n");
        exit(EXIT_FAILURE);
    }       
    
    selected.first = -1;
    selected.second = -1;

    testSprite = Sprite::Load(renderer, "10.png");
    background = Sprite::Load(renderer, "bg.jpg");

    gameGrid[8][0] = 7;
    gameGrid[8][1] = 10;
    gameGrid[8][2] = 5;
    gameGrid[8][3] = 2;
    gameGrid[8][4] = 9;
    gameGrid[8][5] = 9;
    gameGrid[8][6] = 1;
    gameGrid[8][7] = 8;
    gameGrid[8][8] = 9;
    gameGrid[8][9] = 10;
}

void Game::HandleEvents(Game* game){
    SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch (event.type)
        {
        case SDL_QUIT:
            game->Quit();
            break;
        
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                game->Quit();
                break;
            
            default:
                break;
            }

        case SDL_MOUSEBUTTONDOWN:
            SDL_Rect mouseCell;
            mouseCell.x=0;
            mouseCell.y = 0;
            mouseCell.w = cellSize;
            mouseCell.h = cellSize;
            SDL_GetMouseState(&mouseCell.x, &mouseCell.y);
            if(selected.first != -1){
                mouseCell.x = (mouseCell.x -cellSize )/ cellSize;
                mouseCell.y = (mouseCell.y -cellSize )/ cellSize;
                gameGrid[mouseCell.y][mouseCell.x] = gameGrid[selected.second][selected.first];
                printf("selected: %d-%d", selected.first, selected.second);
                SDL_Delay(50);
                gameGrid[selected.second][selected.first] = 0;
                selected.first = -1;
            } else {
                selected.first = (mouseCell.x -cellSize )/ cellSize;
                selected.second = (mouseCell.y -cellSize )/ cellSize;
                printf("i just selected %d-%d", selected.first, selected.second);
            }
            break;
        
        default:
            //std::cout << event.type << std::endl;
            break;
        }
    }
}

void Game::Update(){
    
}

void Game::MouseHover(){
    SDL_Rect mouseCell = {0,0,cellSize,cellSize};
    SDL_GetMouseState(&mouseCell.x, &mouseCell.y);
    mouseCell.x = (mouseCell.x / cellSize) * cellSize;
    mouseCell.y = (mouseCell.y / cellSize) * cellSize;

    if(mouseCell.x >50 && mouseCell.x < 550 && mouseCell.y > 50 && mouseCell.y < 550){
        SDL_SetRenderDrawColor(renderer, 170, 170, 170, 0);
        SDL_RenderFillRect(renderer, &mouseCell);
    }
}

void Game::Draw(){
    //Draw pawns
    SDL_Color White = {255, 255, 255}; 


    SDL_Rect Message_rect; //create a rect
    
    Message_rect.w = 50; // controls the width of the rect
    Message_rect.h = 50; // controls the height of the rect


    for(int y=0;y<10;y++){
        for(int x=0;x<10;x++){
            if(gameGrid[y][x] > 0 && gameGrid[y][x] <=10){
                SDL_Texture* tempSprite = Sprite::Load(renderer, "10.png");
                Message_rect.x = 50 + x*50;  //controls the rect's x coordinate 
                Message_rect.y = 50 + y*50; // controls the rect's y coordinte
                Sprite::Draw(renderer, tempSprite, Message_rect.x, Message_rect.y, Message_rect.w, Message_rect.h);
            }            
        }
    }

    if(Sprite::Draw(renderer, testSprite, 100, 500, 50, 50)){}
        //std::cout << "sprite drawn" << std::endl;
    else{}
        //std::cout << "error drawing sprite" << std::endl;
    testClass();
}

void Game::DrawBackground(){
    SDL_SetTextureBlendMode(background, SDL_BLENDMODE_BLEND);
    Sprite::Draw(renderer, background, 50, 50, 500, 500);
}

void Game::Clean(){

}

bool Game::Running(){
    return running;
}

void Game::Quit(){
    running = false;
}

void Game::testClass(){
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

    int startX = 50;
    int startY = 50;
    int endX = 550;
    int endY = 550;

    //x < 4001
    //x0, y0, x1, y1
    
    for (int x = startX; x < 2 + 50 * 11; x += 50) {
        SDL_RenderDrawLine(renderer, x, startY, x, endY);
    }
    
    for (int y = startY; y < 2 +50 * 11; y += 50) {
        SDL_RenderDrawLine(renderer, startX, y, endX, y);
    }
        SDL_RenderPresent(renderer); //updates the renderer

}