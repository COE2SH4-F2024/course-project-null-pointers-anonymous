#include "Food.h"

Food::Food(GameMechs *thisGMRef)
{
    //allows Food to use the GameMechs class
    mainGameMechsRef = thisGMRef;
    foodPos = new objPos(1, 1, 'o');
}
Food::~Food()
{
    //deallocates foodPos 
    delete foodPos;
}
//two different generateFood methods allow for use depending on if we are checking for singular player or a longer snake

void Food::generateFood(const objPos &blockOff)
{
    bool validPosition = false;
    mainGameMechsRef->setBoard(foodPos->pos->y, foodPos->pos->x, ' '); // Erases previous food from board
    
    while (!validPosition)
    {
        // Generate random position
        srand(time(NULL));
        rand_x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
        rand_y = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1; 
        // Check if the new position is not the blockOff position
        if (!(blockOff.pos->x == rand_x && blockOff.pos->y == rand_y))
        {
            validPosition = true;
        }
    }

 // Update food position
    foodPos->setObjPos(rand_x, rand_y, 'o');
    mainGameMechsRef->setObject(foodPos->getObjPos());
}

void Food::generateFood(const objPosArrayList &blockOff)
{
    bool validPosition = false;
    mainGameMechsRef->setBoard(foodPos->pos->y, foodPos->pos->x, ' '); // Loop to find a valid random position
    
    while (!validPosition)
    {
        // Generate random position
        srand(time(NULL));
        rand_x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
        rand_y = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1; // Check if the new position is not the blockOff position
        // checks for each segment of the snake rather then just the head if snake is longer than one
        for(int i = 0; i<blockOff.getSize(); i++) {
            if (!(blockOff.getElement(i).pos->x == rand_x && blockOff.getElement(i).pos->y == rand_y))
            {
                validPosition = true;
            }
            else {
                validPosition=false;
                break;
            }
        }
        
    }

    // Update food position
    foodPos->setObjPos(rand_x, rand_y, 'o');
    mainGameMechsRef->setObject(foodPos->getObjPos());
}

objPos Food::getFoodPos()
{
    return *foodPos;
}

int Food::getFoodPosX()
{
    return foodPos->pos->x;
}

int Food::getFoodPosY()
{
    return foodPos->pos->y;
}