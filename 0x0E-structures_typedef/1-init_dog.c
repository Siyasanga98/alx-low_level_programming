#include <stdio.h>
/**
*int_dog - initializes structure of type dog
*@d: pointer
*@name: pointer to the name of the dog
*@age: age of dog
*@owner : pointer to owner
*Return: void
*/
struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	d->name = name;
	d->age = age;
	d->owner = owner;
}
int main() 
{
	struct dog my_dog;
	init_dog(&my_dog, "Fido", 3.5, "Betty");printf("My dog's name is %s, age is %.1f, and owner is %s.\n", my_dog.name, my_dog.age, my_dog.owner);
	return 0;
}

