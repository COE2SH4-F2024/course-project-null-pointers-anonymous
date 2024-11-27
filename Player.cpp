#include "Player.h"
 
Player::Player(GameMechs *thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    //figure out how to set up heap allocation
    playerPos = new objPos(10, 8, '8');
   
 
    // more actions to be included
}
 
Player::~Player()
{
    delete playerPos;
   
 
    // delete any heap members here
}
 
objPos Player::getPlayerPos() const
{
    return *playerPos;
    // return the reference to the playerPos arrray list
}
 
void Player::updatePlayerDir()
{
    switch(mainGameMechsRef->getInput())
    {                      
        /*case ' ':  // exit
            mainGameMechsRef->setExitTrue();
            break;
        */
        case 'w':
           
            if(myDir != DOWN)
            {
                myDir = UP;
                cout << "UP" << endl;
            }
            break;
       
        case 's':
            cout << "DOWN" << endl;
            if(myDir != UP)
            {
                myDir = DOWN;
            }
            break;
       
        case 'a':
            cout << "LEFT" << endl;
            if(myDir != RIGHT)
            {
                myDir = LEFT;
            }
            break;
       
        case 'd':
            cout << "RIGHT" << endl;
            if(myDir != LEFT)
            {
                myDir = RIGHT;
            }
            break;
 
        default:
            break;
    }
 
    mainGameMechsRef->clearInput();
}
 
void Player::movePlayer()
{
    // PPA3 Finite myDir Machine logic
    mainGameMechsRef->setBoard(playerPos->pos->y,playerPos->pos->x, ' ');
    switch(myDir)
    {
        case UP:
            if(playerPos->pos->y == 1){
                playerPos->pos->y = mainGameMechsRef->getBoardSizeY() - 2;
               
            }
            else{
                playerPos->pos->y=playerPos->pos->y-1;
            }
            break;
 
        case DOWN:
            if(playerPos->pos->y == mainGameMechsRef->getBoardSizeY() - 2){
                playerPos->pos->y = 1;
               
            }
            else{
                playerPos->pos->y++;                
            }
            break;
       
        case LEFT:
            if(playerPos->pos->x == 1){
                playerPos->pos->x = mainGameMechsRef->getBoardSizeX() - 2;
               
               
            }
            else{
                playerPos->pos->x--;
               
               
            }
            break;
 
        case RIGHT:
            if(playerPos->pos->x == mainGameMechsRef->getBoardSizeX() - 2){
                playerPos->pos->x = 1;
               
               
            }
            else{
                playerPos->pos->x++;
               
               
            }
            break;
    }
}
void Player::drawPlayer()
{ // method to draw the player using the private struct
    mainGameMechsRef->setObject(*playerPos);
  }
 
int Player::getDirection()
{
    return myDir;
}