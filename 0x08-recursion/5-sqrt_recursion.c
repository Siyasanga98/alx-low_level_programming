#include"main.h"
#include <stdio.h>

int _sqrt(int n, int i);

/**
 * _sqrt_recursion - returns square root of a number
 * @n: the number to calculate square root 
 *
 * Return: the natural square root o
 */
int _sqrt_recursion(int n)
{
        return (_sqrt(n, 1));
}

/**
 * _sqrt - calculate the square root of a number
 * @n: number used to find square root 
 * @i: repeats number
 *
 * Return: the square root ,or -1
 */
int _sqrt(int n, int i)
{
        int square = i * i;

        if (square > n)
                return (-1);
        else if (square == n)
                return (i);
        else
                return (_sqrt(n, i + 1));
}

