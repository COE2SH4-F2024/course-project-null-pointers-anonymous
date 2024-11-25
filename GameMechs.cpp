#include "GameMechs.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    score = 0;
    exitFlag = false;
    int i, j;

    board = new char *[boardSizeY];
    for (i = 0; i < boardSizeY; i++)
    {
        board[i] = new char[boardSizeX];
    }
    for (i = 0; i < boardSizeY; i++)
    {
        for (j = 0; j < boardSizeX; j++)
        {
            if (i == boardSizeY - 1 || i == 0 || j == boardSizeX - 1 || j == 0)
            {
                board[i][j] = '#';
            }
            else
            {
                board[i][j] = ' ';
            }
        }
    }
}
GameMechs::GameMechs(int boardX, int boardY)
{
    exitFlag = false;
    score = 0;
    if (boardX <= 0)
    {
        boardX = 30;
    }
    if (boardY <= 0)
    {
        boardY = 15;
    }
    board = new char *[boardY];

    for (int i = 0; i < boardY; i++)
    {
        board[i] = new char[boardX];
    }
    boardSizeX = boardX;
    boardSizeY = boardY;
    for (int i = 0; i < boardSizeY; i++)
    {
        for (int j = 0; j < boardSizeX; j++)
        {
            if (i == boardSizeY - 1 || i == 0 || j == boardSizeX - 1 || j == 0)
            {
                board[i][j] = '#';
            }
            else
            {
                board[i][j] = ' ';
            }
        }
    }
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
    // if apple is touched
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
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

char GameMechs::getBoard(int y, int x)
{
    return board[y][x];
}
void GameMechs::setBoard(int y, int x, char val)
{
    board[y][x] = val;
}
void GameMechs::setObject(const objPos& obj ) {
    board[obj.pos->y][obj.pos->x]=obj.getSymbol();
}

// More methods should be added here