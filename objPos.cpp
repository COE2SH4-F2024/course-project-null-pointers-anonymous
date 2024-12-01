#include "objPos.h" // Include the header file for the objPos class

objPos::objPos() // Default constructor: initializes position to (0,0) and symbol to NULL
{
    pos = new Pos; // Dynamically allocate memory for the Pos object
    pos->x = 0; // Set x-coordinate to 0
    pos->y = 0; // Set y-coordinate to 0
    symbol = 0; // Set symbol to NULL 
}

objPos::objPos(int xPos, int yPos, char sym) // Parameterized constructor: initializes position and symbol to given values
{
    pos = new Pos; // Dynamically allocate memory for the Pos object
    pos->x = xPos; // Set x-coordinate to xPos
    pos->y = yPos; // Set y-coordinate to yPos
    symbol = sym; // Set symbol to sym
}

objPos::~objPos() // Destructor: cleans up dynamically allocated memory
{
    delete pos; // Free the memory allocated for the Pos object
}
objPos::objPos(const objPos &obj)
{
    pos = new Pos; // Allocate new memory for the Pos object
    pos->x = obj.pos->x; // Copy the x-coordinate
    pos->y = obj.pos->y; // Copy the y-coordinate
    symbol = obj.symbol; // Copy the symbol
}
objPos &objPos::operator=(const objPos &obj) // Copy assignment operator: ensures deep copy and avoids self-assignment issues
{
    if (this != &obj) // Avoid self-assignment
    {
        if (obj.pos) // Check if the source object has a valid pos
        {
            delete pos; // Free current memory
            pos = new Pos; // Allocate new memory
            pos->x = obj.pos->x; // Copy the x-coordinate
            pos->y = obj.pos->y; // Copy the y-coordinate
        }
        else
        {
            delete pos; // Free current memory
            pos = nullptr; // Set pos to nullptr
        }
        symbol = obj.symbol;  // Copy the symbol
    }

    return *this; // Return the current object to allow chaining
}

void objPos::setObjPos(objPos o) // Sets the object's position and symbol to match another objPos object
{
    pos->x = o.pos->x; // Copy the x-coordinate
    pos->y = o.pos->y; // Copy the y-coordinate
    symbol = o.symbol; // Copy the symbol
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos; // Set the x-coordinate
    pos->y = yPos; // Set the y-coordinate
    symbol = sym;  // Set the symbol
}

objPos objPos::getObjPos() const // Retrieves the current position and symbol of the object as a new objPos object
{
    objPos returnPos; // Create a new objPos object
    returnPos.pos->x = pos->x; // Copy the x-coordinate
    returnPos.pos->y = pos->y; // Copy the y-coordinate
    returnPos.symbol = symbol; // Copy the symbol

    return returnPos; // Return the new objPos object
}

char objPos::getSymbol() const // Returns the current symbol of the object
{
    return symbol;
}

bool objPos::isPosEqual(const objPos *refPos) const // Checks if the position of the current object is equal to the given reference object
{
    if (refPos && refPos->pos) // Check if the reference object and its pos are valid
    {
        if (refPos->pos->x == pos->x && refPos->pos->y == pos->y) // Compare positions
        {
            return true; //Return true if refeernce is valid
        }
        else
        {
            return false; //Return false if refeernce is invalid
        }
    }
}
char objPos::getSymbolIfPosEqual(const objPos *refPos) const // Returns the symbol if the position matches the reference object's position, otherwise NULL
{
    if (isPosEqual(refPos)) // Check if positions match
        return symbol; // Return the symbol if they do
    else
        return 0; // Return NULL otherwise
}