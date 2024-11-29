#ifndef PLAYER_H
#define PLAYER_H

#include "Food.h"
#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include <Windows.h>

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

public:
    enum Dir
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        STOP
    }; // This is the direction state

    Player(GameMechs *thisGMRef, Food *thisFoodPos);
    ~Player();

    objPos getPlayerPos() const; // Upgrade this in iteration 3.
    void updatePlayerDir();
    void movePlayer();
    void drawPlayer();
    int getDirection();
    int getPlayerPosX();
    int getPlayerPosY();
    bool checkFoodConsumption();
    void increasePlayerLength();
    // More methods to be added here

private:
    objPos *playerPos;
    objPosArrayList *playerPosList; // Upgrade this in iteration 3.
    Food *foodPos;
    enum Dir myDir;

    // Need a reference to the Main Game Mechanisms
    GameMechs *mainGameMechsRef;
};

#endif