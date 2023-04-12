#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* free_grid - Frees a 2D grid previously created
* @grid: 2D grid to be freed
* @height: height of the 2D grid
* Retuen: nothing
*/
void free_grid(int **grid, int height)
{
	int i;

	if (grid != NULL)
	{
		for (i = 0; i < height; i++)
		{
			free(grid[i]);
		}
		free(grid);
	}
}

