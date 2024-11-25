#include "Player.h"


Player::Player(GameMechs* thisGMRef)
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
    switch(myDir)
    {
        case UP:
            if(playerPos.pos->y == 1){
                playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 2;
                // mainGameMechsRef->setObject(playerPos);
            }
            else{
                playerPos.pos->y--;
                // mainGameMechsRef->setObject(playerPos);
            }
            break;

        case DOWN:
            if(playerPos.pos->y == mainGameMechsRef->getBoardSizeY() - 2){
                playerPos.pos->y = 1;
                // mainGameMechsRef->setObject(playerPos);
            }
            else{
                playerPos.pos->y++;
                // mainGameMechsRef->setObject(playerPos);
            }
            break;
        
        case LEFT:
            if(playerPos.pos->x == 1){
                playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 2;
                // mainGameMechsRef->setObject(playerPos);
            }
            else{
                playerPos.pos->x--;
                // mainGameMechsRef->setObject(playerPos);
            }
            break;

        case RIGHT:
            if(playerPos.pos->x == mainGameMechsRef->getBoardSizeX() - 2){
                playerPos.pos->x = 1;
                // mainGameMechsRef->setObject(playerPos);
            }
            else{
                playerPos.pos->x++;
                // mainGameMechsRef->setObject(playerPos);
            }
            break;

    }
    
    
}
void Player::drawPlayer()
{ // method to draw the player using the private struct
    mainGameMechsRef->setObject(playerPos);
}

int Player::getDirection()
{
    return myDir;
}