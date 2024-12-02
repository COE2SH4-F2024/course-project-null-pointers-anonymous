#include "Player.h" //Include the Player class definition

Player::Player(GameMechs *thisGMRef, Food *thisFoodPos) // Constructor for the Player class
{
    mainGameMechsRef = thisGMRef; // Initialize a reference to the game's mechanics
    foodPos = thisFoodPos;     // Initialize a reference to the food position
    myDir = STOP;       // Set the player's initial direction to STOP (assumed as no movement)
    playerPosList = new objPosArrayList();     // Create a dynamic list to store the player's position segments
    playerPos = new objPos(8,10, '8');     // Create the player's initial position at (8, 10) with identifier '8'
    playerPosList->insertHead(playerPos);     // Add the player's initial position to the position list
}

Player::~Player() // Destructor for the Player class
{
    delete playerPosList;     // Delete the player's position list to free heap memory
    delete playerPos;     // Delete the dynamically allocated player position object
}

objPos Player::getPlayerPos() const // Returns the current head position of the player
{
    return playerPosList->getHeadElement();
}

objPosArrayList Player::getPlayer() const // Returns the entire player position list as an object
{
    return *playerPosList; // Dereference and return the position list
}
void Player::updatePlayerDir() // Updates the player's direction based on input from game mechanics
{
    switch (mainGameMechsRef->getInput()) // Check the current input
    {

    case 'w': // Input for moving up

        if (myDir != DOWN) // Prevent reversal from DOWN to UP
        {
            myDir = UP;
        }
        break;

    case 's': // Input for moving down
        if (myDir != UP) // Prevent reversal from UP to DOWN
        {
            myDir = DOWN;
        }
        break;

    case 'a': // Input for moving left
        if (myDir != RIGHT) // Input for moving left
        {
            myDir = LEFT;
        }
        break;

    case 'd': // Input for moving right
        if (myDir != LEFT) // Prevent reversal from LEFT to RIGHT
        {
            myDir = RIGHT;
        }
        break;

    default: // Ignore any invalid input
        break;
    }

    mainGameMechsRef->clearInput();
}

void Player::movePlayer() // Updates the player's position on the board

{
    objPos tail = playerPosList->getTailElement();  // Get the current tail position
    mainGameMechsRef->setBoard(tail.getObjPos().pos->y, tail.getObjPos().pos->x, ' ');     // Clear the tail position on the game board
    switch (myDir)     // Handle movement logic based on the current direction
    {
    case UP:
        if (playerPos->pos->y == 1) // If at the top edge, wrap around to the bottom
        {
            playerPos->pos->y = mainGameMechsRef->getBoardSizeY() - 2;
            playerPosList->insertHead(playerPos);     // Insert the updated position as the new head and remove the old tail
            playerPosList->removeTail();
        }
        else // Otherwise, move up by decreasing y-coordinate
        {
            playerPos->pos->y = playerPos->pos->y - 1;
            playerPosList->insertHead(playerPos); // Insert the updated position as the new head and remove the old tail
            playerPosList->removeTail();
        }
        break; 

    case DOWN:
        if (playerPos->pos->y == mainGameMechsRef->getBoardSizeY() - 2) // At the bottom edge, wrap to the top
        {
            playerPos->pos->y = 1;
            playerPosList->insertHead(playerPos); // Insert the updated position as the new head and remove the old tail
            playerPosList->removeTail();
        }
        else // Otherwise, move down by increasing y-coordinate
        {
            playerPos->pos->y++;
            playerPosList->insertHead(playerPos); // Insert the updated position as the new head and remove the old tail
            playerPosList->removeTail();
        }
        break;

    case LEFT:
        if (playerPos->pos->x == 1) // At the left edge, wrap around to the right
        {
            playerPos->pos->x = mainGameMechsRef->getBoardSizeX() - 2;
            playerPosList->insertHead(playerPos); // Insert the updated position as the new head and remove the old tail
            playerPosList->removeTail();
        }
        else // Otherwise, move left by decreasing x-coordinate
        {
            playerPos->pos->x--;
            playerPosList->insertHead(playerPos); // Insert the updated position as the new head and remove the old tail
            playerPosList->removeTail();
        }
        break;

    case RIGHT:
        if (playerPos->pos->x == mainGameMechsRef->getBoardSizeX() - 2) // At the right edge, wrap to the left
        {
            playerPos->pos->x = 1;
            playerPosList->insertHead(playerPos); // Insert the updated position as the new head and remove the old tail
            playerPosList->removeTail();
        }
        else // Otherwise, move right by increasing x-coordinate
        {
            playerPos->pos->x++;
            playerPosList->insertHead(playerPos); // Insert the updated position as the new head and remove the old tail
            playerPosList->removeTail();
        }
        break;
    }
}
void Player::drawPlayer() // Draws the player on the game board
{
    int i = 0;
    mainGameMechsRef->setObject(playerPosList->getHeadElement()); // Draw the head
    for (i = 1; i < playerPosList->getSize(); i++) // Draw the rest of the body
    {
        
        mainGameMechsRef->setObject(playerPosList->getElement(i));
    }
}

int Player::getDirection() // Returns the current direction of the player
{
    return myDir;
}

int Player::getPlayerPosX() // Returns the x-coordinate of the player's head position
{
    objPos headPos = getPlayerPos();
    return headPos.pos->x;
}

int Player::getPlayerPosY() // Returns the y-coordinate of the player's head position
{
    objPos headPos = getPlayerPos();
    return headPos.pos->y;
}

int Player::checkFoodConsumption() // Checks if the player has consumed food
{
    //returns 0 if there is no collision, 1 if it hits a 'normal' food, and 2 if it hits a 'special' food
    for(int i = 0; i<5; i++) {
        if (playerPos->pos->x == foodPos->getFoodPosX(i) && playerPos->pos->y == foodPos->getFoodPosY(i))
        {
            if(foodPos->getFoodPos(i)->getSymbol()=='o') {
                return 1;
            }
            else if(foodPos->getFoodPos(i)->getSymbol()=='x') {
                return 2;
            }
            else {return 0;}
        }
    }
    return 0;
}
void Player::increasePlayerLength(int incr) // Increases the player's length by adding a new head position
{
    //increments the snake based on the amount inputted
    for(int i = 0; i<incr; i++) {
        playerPosList->insertHead(playerPos);
    }
    
}



bool Player::checkSelfCollision() { // Checks if the player has collided with itself
    objPos head = playerPosList->getHeadElement(); // Get the head position

    for (int i = 1; i < playerPosList->getSize(); i++) // Check against all body segments
    {
        objPos bodySegment = playerPosList->getElement(i);
        if (head.pos->x==bodySegment.pos->x && head.pos->y == bodySegment.pos->y)
        {
            return true; // Collision detected
        }
    }
    return false; // No collision
}

void Player::checkFoodSpawn() // Ensures the food does not spawn on the player's body
{

    for (int i = 0; i < playerPosList->getSize(); i++) // Check all body segments
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