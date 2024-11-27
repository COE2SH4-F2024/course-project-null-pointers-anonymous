#include "objPosArrayList.h"

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize != arrayCapacity)
    {
        for (int i = listSize; i > 0; i--)
        {
            aList[i] = aList[i - 1];
        }
        aList[0] = thisPos;
        listSize++;
    }

    
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize != arrayCapacity)
    {
        aList[listSize++] = thisPos;
    }

    
}

void objPosArrayList::removeHead()
{
    if(listSize != 0)
    {
        for (int i = 0; i < listSize - 1; i++)
        {
            aList[i] = aList[i + 1];
        }

        listSize--;
    }

    
}


void objPosArrayList::removeTail()
{
    if(listSize != 0)
    {
        listSize--;
    }

    
}


objPos objPosArrayList::getHeadElement() const
{
    if(listSize != 0)
    {
        return aList[0];
    }
    
}

objPos objPosArrayList::getTailElement() const
{
    if(listSize != 0)
    {
        return aList[listSize - 1];
    }
}

objPos objPosArrayList::getElement(int index) const
{
    if(listSize != 0 && index >= 0 && index < listSize)
    {
        return aList[index];
    }

    
}
// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
