#include "3-calc.h"
#include "stdio.h"
#include "stdlib.h"
/**
* main -prints results
* @argv:an array of pointer
* @argc:no of arguments supplied
* Return: Always 0.
*/
int main(int argc, char *argv[])
{
    int result;

    if (argc != 4) {
        printf("Usage: %s num1 num2 operator\n", argv[0]);
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    if (*argv[3] == '+') {
        result = num1 + num2;
    }
    else if (*argv[3] == '-') {
        result = num1 - num2;
    }
    else if (*argv[3] == '*') {
        result = num1 * num2;
    }
    else if (*argv[3] == '/') {
        result = num1 / num2;
    }
    else if (*argv[3] == '%') {
        result = num1 % num2;
    }
    else {
        printf("Invalid operator: %c\n", *argv[3]);
        return 1;
    }

    printf("%d\n", result);

    return 0;
}

