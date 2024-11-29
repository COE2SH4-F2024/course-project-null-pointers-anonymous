#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "Food.h"

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
Food *f;

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
    f = new Food(board);
    p = new Player(board, f);
    p->drawPlayer();
    f->generateFood(p->getPlayerPos());
}

void GetInput(void)
{
    if (MacUILib_hasChar())
    {
        board->setInput(MacUILib_getChar());
    }
    else
    {
        board->setInput(0);
    }
}

void RunLogic(void)
{

    switch (board->getInput())
    {
    case 0:
        break;
    case ' ':
        board->setExitTrue();
        break;
    case 'q': // Debug key for incrementing score
        board->incrementScore();
        break;
    default:
        p->updatePlayerDir();
        break;
    }
    if(p->checkSelfCollision()==true) {
        for(int i = 2; i<=7; i++) {
            for(int j = 2; j<=8;j++) {
                if((j==3 || j==4) && i>2) {
                    continue;
                }
                else if (j==5 && (i==3 || i==4)) {
                    continue;
                }
                else if ((j==6 || j==7) && (i>2 && i<7)) {
                    continue;
                }
                else {
                    board->setBoard(j, i, 'x');
                    board->setBoard(j, i+7, 'x');
                }    
            }
        }
        board->setLoseFlag();
        MacUILib_printf("Press SPACE BAR to exit the game!!!!");

    }
    else if (p->checkFoodConsumption() == true && board->getLoseFlagStatus()==false)
    {
        p->increasePlayerLength();
        board->incrementScore();
    }
    p->checkFoodSpawn();
    if(board->getLoseFlagStatus()==false){p->movePlayer();}
    p->drawPlayer();
    board->clearInput();
    if(board->getLoseFlagStatus()) {
        MacUILib_Delay(5000000);
        board->setExitTrue();
    }
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
    MacUILib_printf("\nFood Position: %d %d", f->getFoodPosX(), f->getFoodPosY());
    MacUILib_printf("\nPlayer Position: %d %d", p->getPlayerPosX(), p->getPlayerPosY());
    
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
    delete f;
    delete board;
}