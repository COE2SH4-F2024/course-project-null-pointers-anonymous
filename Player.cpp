#include "Player.h"

Player::Player(GameMechs *thisGMRef, Food *thisFoodPos)
{
    mainGameMechsRef = thisGMRef;
    foodPos = thisFoodPos;
    myDir = STOP;
    playerPosList = new objPosArrayList();
    playerPos = new objPos(8,10, '8');
    playerPosList->insertHead(playerPos);

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
    return playerPosList->getHeadElement();
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
        }
        break;

    case 's':
        if (myDir != UP)
        {
            myDir = DOWN;
        }
        break;

    case 'a':
        if (myDir != RIGHT)
        {
            myDir = LEFT;
        }
        break;

    case 'd':
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
    mainGameMechsRef->setObject(playerPosList->getHeadElement());
    for (i = 1; i < playerPosList->getSize(); i++)
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
    for(int i = 0; i<5; i++) {
        if (playerPos->pos->x == foodPos->getFoodPosX(i) && playerPos->pos->y == foodPos->getFoodPosY(i))
        {
            return true;
        }
    }
    return false;
}
void Player::increasePlayerLength()
{
    playerPosList->insertHead(playerPos);
}
bool Player::checkSelfCollision() {
    objPos head = playerPosList->getHeadElement();

    for (int i = 1; i < playerPosList->getSize(); i++)
    {
        objPos bodySegment = playerPosList->getElement(i);
        if (head.pos->x==bodySegment.pos->x && head.pos->y == bodySegment.pos->y)
        {
            return true;
        }
    }
    return false;
}

void Player::checkFoodSpawn()
{

    for (int i = 0; i < playerPosList->getSize(); i++)
    {
        objPos bodySegment = playerPosList->getElement(i);
        for(int j = 0; j<5; j++) {
            if (foodPos->getFoodPosX(j) == bodySegment.pos->x && foodPos->getFoodPosY(j) == bodySegment.pos->y)
            {
                foodPos->generateFood(*playerPosList);
                break;
            }
        }
        
    }

} 