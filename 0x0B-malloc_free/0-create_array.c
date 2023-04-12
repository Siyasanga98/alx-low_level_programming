#include "main.h"
#include <stdlib.h>
/**
 * create_array - function creates array of size and assign char
 * @c : to assign
 * Return: NULL if fail 
 */
char *create_array(unsigned int size, char c);

{
    if (size == 0)
    {
        return NULL;
    }
    
    char array;
    array = (char *) malloc(size * sizeof(char));
    if (array == NULL)
    {
        return NULL;
    }

    for (unsigned int i = 0; i < size; i++)
    {
        array[i] = c;
    }

    return array;
}
