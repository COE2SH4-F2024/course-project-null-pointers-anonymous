#include "Player.h"

Player::Player(GameMechs *thisGMRef, Food *thisFoodPos)
{
    mainGameMechsRef = thisGMRef;
    foodPos = thisFoodPos;
    myDir = STOP;
    playerPosList = new objPosArrayList();
    playerPos = new objPos(8, 10, '8');
    playerPosList->insertHead(playerPos);
    
    // for three (or less)
    /*playerPos = new objPos(8,10,'8');
    playerPosList->insertHead(playerPos);
    playerPos = new objPos(9,10,'-');
    playerPosList->insertTail(playerPos);
    playerPos = new objPos(10,10,'-');
    playerPosList->insertTail(playerPos);*/

    // more actions to be included
}

Player::~Player()
{
    delete playerPosList;
    delete playerPos;

    

    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    if (playerPosList->getSize() > 0)
    {
        objPos headPos = playerPosList->getHeadElement();
        return headPos;
    }
    // return the reference to the playerPos aray list
}

objPosArrayList Player::getPlayer() const
{
    return *playerPosList;
}
void Player::updatePlayerDir()
{
    switch (mainGameMechsRef->getInput())
    {

    case 'w':

        if (myDir != DOWN)
        {
            myDir = UP;
            cout << "UP" << endl;
        }
        break;

    case 's':
        cout << "DOWN" << endl;
        if (myDir != UP)
        {
            myDir = DOWN;
        }
        break;

    case 'a':
        cout << "LEFT" << endl;
        if (myDir != RIGHT)
        {
            myDir = LEFT;
        }
        break;

    case 'd':
        cout << "RIGHT" << endl;
        if (myDir != LEFT)
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
    objPos tail = playerPosList->getTailElement();
    mainGameMechsRef->setBoard(tail.getObjPos().pos->y, tail.getObjPos().pos->x, ' ');
    switch (myDir)
    {
    case UP:
        if (playerPos->pos->y == 1)
        {
            playerPos->pos->y = mainGameMechsRef->getBoardSizeY() - 2;
            playerPosList->insertHead(playerPos);
            playerPosList->removeTail();
        }
        else
        {
            playerPos->pos->y = playerPos->pos->y - 1;
            playerPosList->insertHead(playerPos);
            playerPosList->removeTail();
        }
        break;

    case DOWN:
        if (playerPos->pos->y == mainGameMechsRef->getBoardSizeY() - 2)
        {
            playerPos->pos->y = 1;
            playerPosList->insertHead(playerPos);
            playerPosList->removeTail();
        }
        else
        {
            playerPos->pos->y++;
            playerPosList->insertHead(playerPos);
            playerPosList->removeTail();
        }
        break;

    case LEFT:
        if (playerPos->pos->x == 1)
        {
            playerPos->pos->x = mainGameMechsRef->getBoardSizeX() - 2;
            playerPosList->insertHead(playerPos);
            playerPosList->removeTail();
        }
        else
        {
            playerPos->pos->x--;
            playerPosList->insertHead(playerPos);
            playerPosList->removeTail();
        }
        break;

    case RIGHT:
        if (playerPos->pos->x == mainGameMechsRef->getBoardSizeX() - 2)
        {
            playerPos->pos->x = 1;
            playerPosList->insertHead(playerPos);
            playerPosList->removeTail();
        }
        else
        {
            playerPos->pos->x++;
            playerPosList->insertHead(playerPos);
            playerPosList->removeTail();
        }
        break;
    }
}
void Player::drawPlayer()
{ // method to draw the player using the private struct
    int i = 0;
    for (i = 0; i < playerPosList->getSize(); i++)
    {
        mainGameMechsRef->setObject(playerPosList->getElement(i));
    }
}

int Player::getDirection()
{
    return myDir;
}

int Player::getPlayerPosX()
{
    objPos headPos = getPlayerPos();
    return headPos.pos->x;
}

int Player::getPlayerPosY()
{
    objPos headPos = getPlayerPos();
    return headPos.pos->y;
}

bool Player::checkFoodConsumption()
{
    if (playerPos->pos->x == foodPos->getFoodPosX() && playerPos->pos->y == foodPos->getFoodPosY())
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Player::increasePlayerLength()
{
    playerPosList->insertHead(playerPos);
}