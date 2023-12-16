#define SDL_MAIN_HANDLED
#include <iostream>

#include "inc/dataDefinition.hpp"
#include "inc/characters/villager.hpp"
#include "inc/buildings/smallHouse.hpp"
#include "inc/characters/NPC.hpp"
#include "inc/game/game.hpp"

Game *game = nullptr;

int main()
{
    constexpr int FPS = 60;
    constexpr int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;
    SDL_SetMainReady();

    game = new Game();

    game->init("test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    // Stuff commented below will be moved inside methods in the Game class
    /*
    SmallHouse smallHouse("Nice place", 10, 20);

    smallHouse.assignCharacter(villager);
    villager.interact(smallHouse);
    //std::cout  << "Energy: " << static_cast<int>(*villager.energy) << std::endl;

    villager.printData();
    smallHouse.getInfo();
    */


    while(game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay> frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }

    }

    game->clean();
    //Villager villager;
    //villager.
    return 0;
}