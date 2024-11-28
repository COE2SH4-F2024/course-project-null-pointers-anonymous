#include "objPos.h"

objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; // NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule

objPos::~objPos()
{
    delete pos;
}
objPos::objPos(const objPos &obj)
{

    if (obj.pos != nullptr)
    {
        this->pos = new Pos;
        this->pos->x = obj.pos->x;
        this->pos->y = obj.pos->y;
        cout << "problem1" << endl;
    }
    else
    {
        pos = nullptr;
    }
    symbol = obj.symbol;
    cout << "problem3" << endl;
}
objPos &objPos::operator=(const objPos &obj)
{
    if (this != &obj)
    {
        if (obj.pos)
        {
            delete pos;
            pos = new Pos;
            pos->x = obj.pos->x;
            pos->y = obj.pos->y;
        }
        else
        {
            delete pos;
            pos = nullptr;
        }
        symbol = obj.symbol;
    }

    return *this;
}

void objPos::setObjPos(const objPos &o)
{
    if (pos == nullptr)
    {
        pos = new Pos;
    }
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    if (pos == nullptr)
    {
        pos = new Pos;
    }
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;

    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos *refPos) const
{
    if (refPos && refPos->pos)
    {
        if (refPos->pos->x == pos->x && refPos->pos->y == pos->y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
char objPos::getSymbolIfPosEqual(const objPos *refPos) const
{
    if (isPosEqual(refPos))
        return symbol;
    else
        return 0;
}