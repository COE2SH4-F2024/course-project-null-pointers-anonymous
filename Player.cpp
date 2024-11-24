#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
     //figure out how to set up heap allocation
    // playerPos = new objPos*;
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
        // PPA3 input processing logic          
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    
}

// More methods to be added