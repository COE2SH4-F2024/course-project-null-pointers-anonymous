#ifndef FOOD_H
#define FOOD_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include <Windows.h>
#include <time.h>

class Food
{

public:
    Food(GameMechs *thisGMRef);
    ~Food();

    void generateFood(const objPos &foodObj);
    void generateFood(const objPosArrayList &foodObj);
    objPos* getFoodPos(int index);
    int getFoodPosX(int index);
    int getFoodPosY(int index);

private:
    //objPos *foodPos;
    objPos *foodPosArray[5];
    GameMechs *mainGameMechsRef;
    int rand_x, rand_y;
};

#endif