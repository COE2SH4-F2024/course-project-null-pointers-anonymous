#include "objPosArrayList.h" // Include the class header file

objPosArrayList::objPosArrayList() // Constructor: initializes an empty list with a fixed capacity
{
    aList = new objPos[ARRAY_MAX_CAP]; // Dynamically allocate an array of objPos objects
    listSize = 0; // Start with an empty list
    arrayCapacity = ARRAY_MAX_CAP; // Set the capacity to the defined maximum
}

objPosArrayList::~objPosArrayList() // Destructor: cleans up dynamically allocated memory
{
    delete[] aList; // Free the memory allocated for the array
}
 
int objPosArrayList::getSize() const // Returns the current size of the list (number of elements in use)
{
    return listSize;
}

void objPosArrayList::insertHead(objPos* thisPos)  // Inserts a new element at the head (front) of the list
{
    if (listSize != arrayCapacity) // Check if there is space for a new element
    {
        for (int i = listSize; i > 0; i--) // Shift all existing elements one position to the right
        {
            aList[i] = aList[i - 1];
        }
        aList[0] = *thisPos; // Insert the new element at the head (index 0)
        listSize++; // Increment the size of the list
    }
}

void objPosArrayList::insertTail(objPos* thisPos) // Inserts a new element at the tail (end) of the list
{
    if (listSize != arrayCapacity) // Check if there is space for a new element
    {
        aList[listSize++] = *thisPos; // Add the element at the current size index, then increment size
    }
}

void objPosArrayList::removeHead() // Removes the head (front) element from the list
{
    if (listSize != 0) // Check if the list is not empty
    {
        for (int i = 0; i < listSize - 1; i++) // Shift all elements to the left to fill the gap created by removing the head
        {
            aList[i] = aList[i + 1];
        }

        listSize--; // Decrease the size of the list
    }
}

void objPosArrayList::removeTail() // Removes the tail (last) element from the list
{
    if (listSize != 0) // Check if the list is not empty
    {
        listSize--; // Simply decrease the size to "remove" the tail
    }
    
}

objPos objPosArrayList::getHeadElement() const // Returns the head (first) element of the list
{
    if (listSize != 0) // Check if the list is not empty
    {
        return aList[0]; // Return the first element
    }
    return objPos(); // Return a default objPos object if the list is empty
}

objPos objPosArrayList::getTailElement() const // Returns the tail (last) element of the list
{
    if (listSize != 0) // Check if the list is not empty
    {
        return aList[listSize - 1]; // Return the last element
    }
    return objPos(); // Return a default objPos object if the list is empty
}

objPos objPosArrayList::getElement(int index) const // Returns the element at the specified index
{
    if (index < 0 || index >= listSize) // Check if the index is out of bounds
    {
        return objPos(); // Return a default objPos object for invalid index
    }
    return aList[index]; // Return the element at the given index
}
