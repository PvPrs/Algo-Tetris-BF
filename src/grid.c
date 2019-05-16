//
// Created by Dave Van bochove on 2019-05-15.
//
#include "../includes/fillit.h"

/**
 * Genererates a 2D Array performing as a grid
 * the size of the grid is based on the amount of tetrimino's
 * possible minimum required elements is = √𝑛 ⋅ 4
 * @param size
 * @param size_elem
 * @return
 */
char	**ft_grid_gen(int size)
{
	char	**map;
	int		index;
	int		elem_index;
	int		sq_root;

	index = 0;
	elem_index = 0;
	sq_root = ft_sqrt(size * 4);
	map = (char**)malloc((size * sizeof(char*)) + 1);
	map[sq_root] = NULL;
	while (index < sq_root)
	{
		map[index] = (char*)malloc(sq_root * sizeof(char));
		while (elem_index < sq_root)
		{
			map[index][elem_index] = '.';
			elem_index++;
		}
		index++;
		elem_index = 0;
	}
	printf("GENERATED NEW GRID of size %s!\n", map[0]);
	return(map);
}

void		clear_grid(char **grid)
{
	int index;
	int size;

	size = ft_strlen(grid[0]);
	index = 0;
	while (index < size) {
		free(grid[index]);
		index++;
	}
}

void		delete_from_grid(char **grid, t_tetrimino current)
{
	int x;
	int y;

	y = 0;
	while (grid[y] != NULL)
	{
		x = 0;
		while (grid[y][x] != '\0')
		{
			if (grid[y][x] == current.letter)
				grid[y][x] = '.';
			x++;
		}
		y++;
	}
}

int		add_to_grid(char **grid, t_tetrimino current, int index_y, int index_x)
{
	int elem;

	elem = 0;
	while (elem < 4)
	{
		grid[index_y + current.y[elem]][index_x + current.x[elem]] = current.letter;
		elem++;
	}
	return (1);
}