/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   grid.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-boc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 20:11:20 by dvan-boc      #+#    #+#                 */
/*   Updated: 2019/05/21 20:11:25 by dvan-boc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Genererates a 2D Array performing as a grid
** the size of the grid is based on the amount of tetrimino's
** possible minimum required elements is = √𝑛 ⋅ 4
** @param size
** @param size_elem
** @return
*/

char		**ft_grid_gen(size_t size)
{
	char	**map;
	int		index;
	int		elem_index;
	int		grid_size;

	index = 0;
	elem_index = 0;
	grid_size = 7;
	map = malloc((size * sizeof(*map)) + 1);
	map[grid_size] = NULL;
	while (index < grid_size)
	{
		map[index] = malloc(grid_size * sizeof(char) + 1);
		map[index][grid_size] = '\0';
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

/*
** Calculates the minimum required grid sizze
** the size of the grid is based on the amount of tetrimino's
** possible minimum required elements is = √𝑛 ⋅ 4
** @param size
** @return size
*/

size_t		ft_calc_sqrt(size_t size)
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

/*
** Deletes a specific tetrimino from the grid
** @param grid represents the array to remove from
** @param current represents the current node
** @return
*/

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

/*
** Adds a specific tetrimino to the grid
** @param grid represents the array to add to
** @param current represents the current node
** @param index_y line numbers
** @param index_x horizontal index
** @return
*/

int			add_to_grid(char **grid, t_tetrimino current, int y, int x)
{
	int elem;

	elem = 0;
	current.grid_y = y;
	current.grid_x = x;
	while (elem < 4)
	{
		grid[y + current.y[elem]][x + current.x[elem]] = current.letter;
		elem++;
	}
	return (1);
}
