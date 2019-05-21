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

void	ft_solve(t_tetrimino *current, size_t size)
{
	char **grid;
	int y;

	y = 0;
	grid = ft_grid_gen(size);
	subtract_coordinates(current, 1);
	while (check_all_tetr(grid, current, 0, 0) == -1)
	{
		grid = ft_grid_gen(ft_strlen(grid[0]) + 1);
	}
	while (grid[y] != NULL)
	{
		printf("%s\n", grid[y]);
		y++;
	}
}

/*
** Checks all the tetrimino's in order, in a rescursive manner.
** @param size
** @return -1 = Checked the entire grid
** @return 0 = doesn't fit on specific index
** @return 1 = fits.
** Y = vertical - line number
** X = horizontal - on the line
*/

int		check_all_tetr(char **grid, t_tetrimino *curr, int index_y, int index_x)
{
	int size;
	int check_ret;

	size = ft_strlen(grid[0]);
	check_ret = check_tetrimino(grid, *curr, index_y, index_x);
	if (check_ret == 0)
	{
		if (index_x < (size - 1))
			++index_x;
		else
		{
			++index_y;
			index_x = 0;
		}
	}
	if (check_ret == 1)
	{
		if (!(curr->next->letter > 'A' && curr->next->letter < 'Z'))
			return (1);
		curr->grid_x = index_x;
		curr->grid_y = index_y;
		curr = curr->next;
		index_x = 0;
		index_y = 0;
	}
	if (check_ret == -1)
	{
		curr = curr->prev;
		delete_from_grid(grid, *curr);
		if (curr->prev == NULL)
			return (-1);
		if (index_x < (size - 1))
			return (check_all_tetr(grid, curr, curr->grid_y, curr->grid_x + 1));
		else
			return (check_all_tetr(grid, curr, curr->grid_y + 1, 0));
	}
	return (check_all_tetr(grid, curr, index_y, index_x));
}

/*
** Checks a single Tetrimino.
** @return -1 = Checked the entire grid
** @return 0 = doesn't fit on specific index
** @return 1 = fits.
** Y = vertical - line number
** X = horizontal - on the line
*/

int		check_tetrimino(char **grid, t_tetrimino current, int index_y, int index_x)
{
	int y;
	int x;
	int size;

	size = strlen(grid[0]);
	x = 0;
	y = 0;
	while (x < 4)
	{
		if (index_y + current.y[y] >= size || (index_x + current.x[x] >= size && index_y >= size))
			return (-1);
		if (grid[index_y + current.y[y]][index_x + current.x[x]] != '.')
			return (0);
		x++;
		y++;
	}
	return (add_to_grid(grid, current, index_y, index_x));
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

void		subtract_coordinates(t_tetrimino *head, int check)
{
	t_tetrimino	*current;
	int			lowest;
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
		subtract_coordinates(head, 0);
}

