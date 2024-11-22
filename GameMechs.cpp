#include "GameMechs.h"

GameMechs::GameMechs()
{
    int boardsizeX = 30;
    int boardsizeY = 15;
    int **board = new int * [boardsizeX];

    for (int i = 0; i < boardsizeX; i++)
    {
        board[i] = new int[boardsizeY];
    }

    for (int i = 0; i < boardsizeX; i++)
        for (int j = 0; j < boardsizeY; j++)
            board[i][j] = 0;
    
    // starting position

GameMechs::GameMechs(int boardX, int boardY)
{
    if(boardX <= 0) {
        boardX=10;
    }
    if(boardY <=0) {
        boardY=20;
    }
    int **board = new int * [boardX];

    for (int i = 0; i < boardX; i++)
    {
        board[i] = new int[boardY];
    }

    for (int i = 0; i < boardX; i++)
        for (int j = 0; j < boardY; j++)
            board[i][j] = 0;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    for (int i = 0; i < boardSizeX; ++i)
    {
        delete[] board[i];
    }
    delete[] board;
}


bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    //if apple is touched 
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    if(input = ' ') {
        exitFlag=true;
    }
}

void GameMechs::setLoseFlag()
{
}

void GameMechs::setInput(char this_input)
{
    if(this_input!=0) {
        
    }
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here