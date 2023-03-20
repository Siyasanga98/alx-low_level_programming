#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
*main - check for number if its is positive or negative
*
*Return  0 (Success)
*/
int main(void)
{
	int n;

randomize the rand() function
srand(time(NULL));

n = rand() % (RAND_MAX + 1);
if (n > 0)
{
	printf("The number %d is positive\n", n);
}
else if (n == 0)
printf("The number %d is zero\n", n);
}
else
{
printf("The number %d is negative\n", n);
}

return 0
