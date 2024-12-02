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

    //allocate memory for the game board, food object, and player object
    board = new GameMechs();
    f = new Food(board);
    p = new Player(board, f);

    //draws initial player position 
    p->drawPlayer();

    //generates first food position
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
    //cases check input and either will set exit flag or allow for direction change if a valid input is given
    switch (board->getInput())
    {
    case 0:
        break;
    case ' ':
        board->setExitTrue();
        break;
    default:
        p->updatePlayerDir();
        break;
    }
    // when player loses it will draw 'GG' on the board
    if(p->checkSelfCollision()==true) {
        board->setLoseFlag();
        MacUILib_printf("Press SPACE BAR to exit the game!!!!");

    }
    //assuming food is consumed and player has not already lost, will increment score and increase length
    //depending on which type of food was consumed, will either grow normally or grow in a different way!
    else if (p->checkFoodConsumption() == 1 && board->getLoseFlagStatus()==false)
    {
        p->increasePlayerLength(1);
        board->incrementScore(1);
    }
    else if (p->checkFoodConsumption() == 2 && board->getLoseFlagStatus() == false)
    {
        p->increasePlayerLength(3);
        board->incrementScore(10);
    }
    //ensures food is spawned properly and not overlapping snake
    p->checkFoodSpawn();
    //updates player position
    if(board->getLoseFlagStatus()==false){p->movePlayer();}
    //draws full snake onto board
    p->drawPlayer();
    board->clearInput();

    if(board->getLoseFlagStatus()) {
        //pauses code for 5 seconds and displays lose sequence
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
    MacUILib_printf(" w = up, a = left, s = down, d = right | space = stop\n");
    MacUILib_printf("Score: %d", board->getScore());
    if(board->getLoseFlagStatus()) {
        MacUILib_Delay(3000000);
    }

    
}
void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{
    MacUILib_clearScreen();

    MacUILib_uninit();
    //deallocates memory
    delete p;
    delete f;
    delete board;
}