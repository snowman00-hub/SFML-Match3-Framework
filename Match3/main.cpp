#include "Game.h"

int main()
{
    Game game(800, 600, "Match3");
    game.Init();
    game.Play();

    return 0;
}