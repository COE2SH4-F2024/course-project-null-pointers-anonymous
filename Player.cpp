#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    //figure out how to set up heap allocation
    
    objPos playerPos(10, 10, '8');

    mainGameMechsRef->setObject(playerPos);

    // more actions to be included
    
}


Player::~Player()
{
    // delete any heap members here
    
}

objPos Player::getPlayerPos() const
{
    return playerPos;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    

    
}

void Player::movePlayer()
{
    // PPA3 Finite myDir Machine logic
    
    
}
void Player::drawPlayer()
{ // method to draw the player using the private struct
    mainGameMechsRef->setObject(playerPos);
}

// More methods to be added

//Benji PPA Copy Paste
// Update PlayerDIR
/*if (mainGameMechsRef->getInput() != 0) // if not null character
    {
        Dir prev_val = LEFT;
        switch (mainGameMechsRef->getInput())
        {
            case ' ': // exit
                mainGameMechsRef->setExitTrue();
                break;
            case 'w':
                myDir = UP;
                break;
            case 'a':
                myDir = LEFT;

                break;
            case 's':
                myDir = DOWN;

                break;
            case 'd':
                myDir = RIGHT;
                break;
            default:
                myDir = prev_val;
                break;
        }
        // Set of ifs will check if input is invalid
        if (prev_val == LEFT && myDir == RIGHT)
        {
            myDir = prev_val;
            mainGameMechsRef->setBoard(playerPos.pos->y, playerPos.pos->x, ' '); // makes sure you don't go left to right
        }
        else if (prev_val == RIGHT && myDir == LEFT)
        {
            myDir = prev_val;
            mainGameMechsRef->setBoard(playerPos.pos->y, playerPos.pos->x, ' ');
        }
        else if (prev_val == UP && myDir == DOWN)
        {
            myDir = prev_val;
            mainGameMechsRef->setBoard(playerPos.pos->y, playerPos.pos->x, ' ');
        }
        else if (prev_val == DOWN && myDir == UP)
        {
            myDir = prev_val;
            mainGameMechsRef->setBoard(playerPos.pos->y, playerPos.pos->x, ' ');
        }
        else
        {
            prev_val = myDir;
            mainGameMechsRef->setBoard(playerPos.pos->y, playerPos.pos->x, ' ');
        }



    }*/
   //MOVE PLAYER
/*if (myDir == LEFT)
    {
        if (playerPos.pos->x > 1)
        {
            mainGameMechsRef->setBoard(playerPos.pos->y, playerPos.pos->x, ' ');
            playerPos.pos->x -= 1;
            playerPos.setObjPos(playerPos.pos->y, playerPos.pos->x, playerPos.symbol);
            mainGameMechsRef->setObject(playerPos);
        }
        else
        {
            mainGameMechsRef->setBoard(playerPos.pos->y, playerPos.pos->x, ' ');
            playerPos.pos->x = mainGameMechsRef->getBoardSizeX()-1;
            playerPos.setObjPos(playerPos.pos->y, playerPos.pos->x, playerPos.symbol);
            mainGameMechsRef->setObject(playerPos);
        }
    }
    else if (myDir == RIGHT)
    {
        if (playerPos.pos->x < mainGameMechsRef->getBoardSizeX() - 1)
        {
            mainGameMechsRef->setBoard(playerPos.pos->y, playerPos.pos->x, ' ');
            playerPos.pos->x += 1;
            playerPos.setObjPos(playerPos.pos->y, playerPos.pos->x, playerPos.symbol);
            mainGameMechsRef->setObject(playerPos);
        }
        else
        {
           mainGameMechsRef->setBoard(playerPos.pos->y, playerPos.pos->x, ' ');
            playerPos.pos->x = 1;
            playerPos.setObjPos(playerPos.pos->y, playerPos.pos->x, playerPos.symbol);
            mainGameMechsRef->setObject(playerPos);
        }
    }
    else if (myDir == UP)
    {
        if (playerPos.pos->y > 1)
        {
            mainGameMechsRef->setBoard(playerPos.pos->y, playerPos.pos->x, ' ');
            playerPos.pos->y -= 1;
            playerPos.setObjPos(playerPos.pos->y, playerPos.pos->x, playerPos.symbol);
            mainGameMechsRef->setObject(playerPos);
        }
        else
        {
            mainGameMechsRef->setBoard(playerPos.pos->y, playerPos.pos->x, ' ');
            playerPos.pos->y = mainGameMechsRef->getBoardSizeX() - 1;
            playerPos.setObjPos(playerPos.pos->y, playerPos.pos->x, playerPos.symbol);
            mainGameMechsRef->setObject(playerPos);
        }
    }
    else if (myDir == DOWN)
    {
        if (playerPos.pos->y < mainGameMechsRef->getBoardSizeY()-1)
        {
            mainGameMechsRef->setBoard(playerPos.pos->y, playerPos.pos->x, ' ');
            playerPos.pos->y += 1;
            playerPos.setObjPos(playerPos.pos->y, playerPos.pos->x, playerPos.symbol);
            mainGameMechsRef->setObject(playerPos);
        }
        else
        {
            mainGameMechsRef->setBoard(playerPos.pos->y, playerPos.pos->x, ' ');
            playerPos.pos->y = 1;
            playerPos.setObjPos(playerPos.pos->y, playerPos.pos->x, playerPos.symbol);
            mainGameMechsRef->setObject(playerPos);
        }
    }*/