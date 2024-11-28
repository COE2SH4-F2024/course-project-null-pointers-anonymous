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

    void generateFood(const objPosArrayList &blockOff);
    objPos getFoodPos();
    int getFoodPosX();
    int getFoodPosY();

private:
    objPos *foodPos;
    GameMechs *mainGameMechsRef;
    int rand_x, rand_y;
};

#endif