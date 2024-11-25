#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

GameMechs *board;
Player *p;

int main(void)
{

    Initialize();

    while (board->getExitFlagStatus() == false)
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();
}

void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    board = new GameMechs();
    p = new Player(board);
    p->drawPlayer();
}

void GetInput(void)
{
    if (MacUILib_hasChar())
    {
        board->setInput(MacUILib_getChar());
    }
    else {
        board->setInput(0);
    }
}

void RunLogic(void)
{
    switch(board->getInput()) {
        case 0:
            break;
        case ' ':
            board->setExitTrue();
            break;
        case 'q':
            board->incrementScore();
            break;
        default:
            p->updatePlayerDir();
            break;
    }

    p->movePlayer();
    p->drawPlayer();
    board->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    // actually prints out board
    int xBound = board->getBoardSizeX(), yBound = board->getBoardSizeY();
    int i, j;
    for (i = 0; i < yBound; i++)
    {
        for (j = 0; j < xBound; j++)
        {
            MacUILib_printf("%c", board->getBoard(i, j));
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf(" w = up, a = left, s = down, d = right | space = stop | cannot go in reverse direction, only perpendicular\n");
    MacUILib_printf("Score: %d", board->getScore());

    MacUILib_printf("\nDirection: %d", p->getDirection());

}
void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{
    MacUILib_clearScreen();

    MacUILib_uninit();
    delete p;
    delete board;
}