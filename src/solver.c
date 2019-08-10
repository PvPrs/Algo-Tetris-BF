/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-boc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 16:40:44 by dvan-boc      #+#    #+#                 */
/*   Updated: 2019/04/02 16:40:45 by dvan-boc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "stdlib.h"

/*
** Find the smallest possible square with holes to
** Each tetrimino must be placed in specific order
** starting from Tetrimino 'A' until the last set.
** A maximum of 26 Tetrimino's are allowed.
**
** Algorithm:
** First we place Tetrimino set 'A', in the most upleft corner.
** Next we place set 'B', if it does not fit,
** we move The previous one, until 'B' fits.
** Once 'B' fits, we continue to 'C',
** if 'C' doesn't fit we move around 'B' until it fits,
** SCENARIO: It just doesn't fit!
** We start moving around 'A' again, Followed by 'B' until 'C' fits.
**
** @return a string forming a solved set of Tetrimino's
** 			AABD\n
** 			AABD\n
** 			CCBD\n
** 			CCBD\n
*/

void		ft_solve(t_tetrimino *current, size_t size)
{
	char	**grid;
	int		i;

	i = 0;
	grid = ft_grid_gen(size);
	subtract_coordinates(current, 1, 2100);
	while (check_all_tetr(grid, current) == 0)
	{
		size++;
		grid = ft_grid_gen(size);
	}
	while (grid[i] != NULL)
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
		i++;
	}
	ft_free_array((void **)grid);
}

int			check_all_tetr(char **grid, t_tetrimino *curr)
{
	int ind_y;
	int ind_x;

	ind_y = 0;
	ind_x = 0;
	if (curr->next == 0)
		return (1);
	while (grid[ind_y])
	{
		if (check_tetr(grid, *curr, ind_y, ind_x) == 1)
		{
			add_to_grid(grid, *curr, ind_y, ind_x);
			if (check_all_tetr(grid, curr->next) == 1)
				return (1);
			else
				delete_from_grid(grid, *curr);
		}
		ind_x++;
		if (grid[ind_y][ind_x] == '\0')
		{
			ind_x = 0;
			ind_y++;
		}
	}
	return (0);
}

/*
** Checks a single Tetrimino.
** @return -1 = Checked the entire grid
** @return 0 = doesn't fit on specific index
** @return 1 = fits.
** Y = vertical - line number
** X = horizontal - on the line
*/

int			check_tetr(char **grid, t_tetrimino curr, int ind_y, int ind_x)
{
	int coord;
	int size;

	size = ft_strlen(grid[0]);
	coord = 0;
	while (coord < 4)
	{
		if (ind_y + curr.y[coord] >= size)
			return (0);
		if (grid[ind_y + curr.y[coord]][ind_x + curr.x[coord]] != '.')
			return (0);
		coord++;
	}
	return (1);
}

/*
** Subtracts the coordinates so that both X and Y
** are decreased to the most upleft top,
** eliminating all the unused coordinates.
** @Formula: find the lowest X or Y coordinate
** and decrease all the coords by the lowest.
**
** 	EXAMPLE:
**    2,2	becomes		0, 1
**    3,1	becomes		1, 0
**    3,2	becomes		1, 1
**    3,3	becomes		1, 2
*/

void		subtract_coordinates(t_tetrimino *head, int check, int lowest)
{
	t_tetrimino	*current;
	int			index;
	int			*coords;

	current = head;
	while (current->next != NULL)
	{
		lowest = 2100;
		index = 0;
		coords = (check) ? current->x : current->y;
		while (index < 4)
		{
			lowest = (coords[index] < lowest) ? coords[index] : lowest;
			index++;
		}
		index = 0;
		while (index < 4)
		{
			coords[index] -= lowest;
			index++;
		}
		current = current->next;
	}
	if (check)
		subtract_coordinates(head, 0, 2100);
}
