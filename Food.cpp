#include "Food.h"

Food::Food(GameMechs *thisGMRef)
{
    //allows Food to use the GameMechs class
    mainGameMechsRef = thisGMRef;
    for(int i = 0; i<5; i++) {
        foodPosArray[i] = new objPos(1, 1, 'o');
    }
    
}
Food::~Food()
{
    //deallocates foodPos 
    for(int i = 0; i<5; i++) {
        delete foodPosArray[i];
    }
    
}
//two different generateFood methods allow for use depending on if we are checking for singular player or a longer snake

void Food::generateFood(const objPos &blockOff)
{
    srand(time(NULL));
    for(int i = 0; i<5; i++) {
        
        bool validPosition = false;
        mainGameMechsRef->setBoard(foodPosArray[i]->pos->y, foodPosArray[i]->pos->x, ' '); // Erases previous food from board

        while (!validPosition)
        {
            // Generate random position
            rand_x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
            rand_y = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
            // Check if the new position is not the blockOff position
            if (!(blockOff.pos->x == rand_x && blockOff.pos->y == rand_y))
            {
                validPosition = true;
                if (i > 0)
                {
                    foodPosArray[i]->setObjPos(rand_x, rand_y, 'o');
                }
                else
                {
                    foodPosArray[i]->setObjPos(rand_x, rand_y, 'x');
                }
                mainGameMechsRef->setObject(foodPosArray[i]->getObjPos());
                for (int j = 0; j < i; j++) // ensures two items / player and item are not spawning in same position
                {
                    if(j==i) {
                        continue;
                    }
                    else if (rand_x == foodPosArray[j]->getObjPos().pos->x && rand_y == foodPosArray[j]->getObjPos().pos->y) // makes sure not in same spot as other food
                    {
                        srand(time(NULL));
                        rand_x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
                        rand_x = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
                        validPosition = false;
                        
                    }
                }
            }
        }
    }
    

 // Update food position
    
}

void Food::generateFood(const objPosArrayList &blockOff)
{
    srand(time(NULL));
    for(int i = 0; i<5; i++) {
        bool validPosition = false;
        mainGameMechsRef->setBoard(foodPosArray[i]->pos->y, foodPosArray[i]->pos->x, ' '); // Loop to find a valid random position
        while (!validPosition)
        {

            // Generate random position
            rand_x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
            rand_y = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1; // Check if the new position is not the blockOff position
            // checks for each segment of the snake rather then just the head if snake is longer than one

            validPosition = true;
            for (int j = 0; j < blockOff.getSize(); j++)
            {
                if (blockOff.getElement(j).pos->x == rand_x && blockOff.getElement(j).pos->y == rand_y)
                {
                    validPosition = false;
                    break;
                }

                // Update food position
            }
            for (int j = 0; j < i; j++) // ensures two items  are not spawning in same position
            {
                if (j == i)
                {
                    continue;
                }
                else if (rand_x == foodPosArray[j]->getObjPos().pos->x && rand_y == foodPosArray[j]->getObjPos().pos->y) // makes sure not in same spot as other food
                {
                    srand(time(NULL));
                    rand_x = rand() % (mainGameMechsRef->getBoardSizeX() - 2) + 1;
                    rand_x = rand() % (mainGameMechsRef->getBoardSizeY() - 2) + 1;
                    validPosition = false;
                }
            }
        }
        if(i>0) {
            foodPosArray[i]->setObjPos(rand_x, rand_y, 'o');
        }
        else {
            foodPosArray[i]->setObjPos(rand_x,rand_y,'x');
        }
        
        mainGameMechsRef->setObject(foodPosArray[i]->getObjPos());
    }
    
}

objPos* Food::getFoodPos(int index)
{
    return foodPosArray[index];
}

int Food::getFoodPosX(int index)
{
    return foodPosArray[index]->pos->x;
}

int Food::getFoodPosY(int index)
{
    return foodPosArray[index]->pos->y;
}