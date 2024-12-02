#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    score = 0;
    exitFlag = false, loseFlag=false;
    int i, j;
    // constructor class will make the game board so that it can be drawn on. Additionally allocates memory for it
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
    //set of ifs in case invalid inputs are given
    if (boardX <= 0)
    {
        boardX = 30;
    }
    if (boardY <= 0)
    {
        boardY = 15;
    }
    
    //memory allocated, board array set up
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

GameMechs::~GameMechs()
{
    //deletes all allocated memory for the board
    for (int i = 0; i < boardSizeX; ++i)
    {
        delete board[i];
    }
    delete[] board;
}

//getter methods

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

void GameMechs::incrementScore(int incr)
{
    //increments score based on amount inputted
    score+=incr;
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
    loseFlag= true;
    for (int i = 2; i <= 7; i++)
    {
        for (int j = 2; j <= 8; j++)
        {
            if ((j == 3 || j == 4) && i > 2)
            {
                continue;
            }
            else if (j == 5 && (i == 3 || i == 4))
            {
                continue;
            }
            else if ((j == 6 || j == 7) && (i > 2 && i < 7))
            {
                continue;
            }
            else
            {
                setBoard(j, i, 'x');
                setBoard(j, i + 7, 'x');
            }
        }
    }
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
    //given an object, it will check if it is a non-NULL object and then draw it onto the board
    if (obj.pos == nullptr && obj.getSymbol()==0)
    {return;}

    board[obj.pos->y][obj.pos->x] = obj.getSymbol();
    
}

// More methods should be added here