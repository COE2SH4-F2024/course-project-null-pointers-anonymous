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




GameMechs* x = new GameMechs();
Player *p = new Player(x);

int main(void)
{

    Initialize();

    while(x->getExitFlagStatus()== false)  
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

    exitFlag = false;
}

void GetInput(void)
{
    if (MacUILib_hasChar())
    {
        x->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    // actually prints out board
    for (int i = 0; i < x->getBoardSizeY(); i++)
    {
        for (int j = 0; j < x->getBoardSizeX(); j++)
        {
            MacUILib_printf("%c", x->getBoard(i,j));
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf(" w = up, a = left, s = down, d = right | space = stop | cannot go in reverse direction, only perpendicular\n");

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
    delete[] p;
    delete[] x;
}
