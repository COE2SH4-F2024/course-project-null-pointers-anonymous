#include "Player.h"

Player::Player(GameMechs *thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
     //figure out how to set up heap allocation
    objPos playerPos(15, 8, '8');
     

    // more actions to be included
}

Player::~Player()
{
    delete[] mainGameMechsRef;
    

    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    return playerPos;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    
    if(mainGameMechsRef->getInput() != 0)  // if not null character
    {
        switch(mainGameMechsRef->getInput())
        {                      
            case ' ':  // exit
                mainGameMechsRef->setExitTrue();
                break;
            
            case 'w':
                if(myDir != DOWN)
                {
                    myDir = UP;
                }
                break;
            
            case 's':
                if(myDir != UP)
                {
                    myDir = DOWN;
                }
                break;
            
            case 'a':
                if(myDir != RIGHT)
                {
                    myDir = LEFT;
                }
                break;
            
            case 'd':
                if(myDir != LEFT)
                {
                    myDir = RIGHT;
                }
                break;

            default:
                break;
        }
    }
    
}

void Player::movePlayer()
{
    // PPA3 Finite myDir Machine logic
}
void Player::drawPlayer()
{ // method to draw the player using the private struct
    playerPos.setObjPos(playerPos.pos->y,playerPos.pos->x,'8');
    mainGameMechsRef->setObject(playerPos);
   // mainGameMechsRef->setBoard(playerPos.pos->x,playerPos.pos->y,playerPos.getSymbol());
}

int Player::getDirection()
{
    return myDir;
}
