#include "dog.h"
#include <stdio.h>
/**
*int_dog - initializes structure of type dog
*@d: pointer
*@name: pointer to the name of the dog
*@age: age of dog
*@owner : pointer to owner
*Return: void
*/
void int_dog(struct dog *d, char *name, float age, char *owner)
{
	struct dog
{
	char *name;
	float age;
	char *owner;
};

	if(d) 
	{
	d ->name = name;
	d ->age = age;
	d ->owner = owner;
	}
}
