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
char	**ft_grid_gen(size_t size)
{
	char	**map;
	int		index;
	int		elem_index;
	int		grid_size;

	index = 0;
	elem_index = 0;
	grid_size = ft_calc_sqrt(size);
	map = (char**)malloc((size * sizeof(char*)) + 1);
	map[grid_size] = NULL;
	while (index < grid_size)
	{
		map[index] = (char*)malloc(grid_size * sizeof(char));
		while (elem_index < grid_size)
		{
			map[index][elem_index] = '.';
			elem_index++;
		}
		index++;
		elem_index = 0;
	}
	return (map);
}

size_t			ft_calc_sqrt(size_t size)
{
	size_t min_root;
	size_t blocks;

	min_root = 2;
	blocks = size * 4;
	while (min_root < blocks)
	{
		if (min_root * min_root == blocks)
			return (min_root);
		if (min_root * min_root > blocks)
			return (min_root);
		min_root++;
	}
	return (0);
}

void		delete_from_grid(char **grid, t_tetrimino current)
{
	int x;
	int y;
	int size;

	size = ft_strlen(grid[0]);
	y = 0;
	while (y < size)
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
	current.grid_y = index_y;
	current.grid_x = index_x;
	while (elem < 4)
	{
		grid[index_y + current.y[elem]][index_x + current.x[elem]] = current.letter;
		elem++;
	}
	return (1);
}