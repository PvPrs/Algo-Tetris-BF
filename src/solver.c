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

/**
 * Find the smallest possible square with holes to
 * Each tetrimino must be placed in specific order starting from Tetrimino 'A' until the last set.
 * A maximum of 26 Tetrimino's are allowed.
 *
 * Algorithm:
 * First we place Tetrimino set 'A', in the most upleft corner.
 * Next we place set 'B', if it does not fit, we move The previous one, until 'B' fits.
 * Once 'B' fits, we continue to 'C', if 'C' doesn't fit we move around 'B' until it fits,
 * SCENARIO: It just doesn't fit! We start moving around 'A' again, Followed by 'B' until 'C' fits.
 *
 * @return a string forming a solved set of Tetrimino's
 * 			AABD\n
 * 			AABD\n
 * 			CCBD\n
 * 			CCBD\n
 *
 * 			check if 'a' fits, if 'a' fits, check if Return ((recursive func)current->next fits),
 * 			if it fits, check if the next Return ((recursive func)current->next fits), if ret == 1 succeed.
 *
 */

void	ft_solve(t_tetrimino *current, size_t size)
{
	char **grid;
	int y;

	y = 0;
	grid = ft_grid_gen(size);
	subtractCoordinates(current, 1);
	while (check_all_tetriminos(grid, current, 0, 0) == -1)
	{
		grid = ft_grid_gen(8);
	}
	while (grid[y] != NULL)
	{
		printf("%s\n", grid[y]);
		y++;
	}
}

/**
 * @param size
 * MAKE THIS RECURSIIVE AND RETURN THE CORRECT THE RETURN STATEMENTS ON THE RIGHT TIME.
 * AND INCREASE THE INDEX_Y AND INDEX_X everytime it does not fit at the specific index.
 * @return -1 = Checked the entire grid, 0 = doesn't fit on specific index, 1 = fits.
 * Y = vertical - line number
 * X = horizontal - on the line
 */

int		check_all_tetriminos(char **grid, t_tetrimino *current, int index_y, int index_x)
{
	int size;
	int check_ret;
	int y;

	size = ft_strlen(grid[0]);
	check_ret = check_tetrimino(grid, *current, index_y, index_x);
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
		if (!(current->next->letter > 'A' && current->next->letter < 'Z'))
			return (1);
		current->grid_x = index_x;
		current->grid_y = index_y;
		current = current->next;
		index_x = 0;
		index_y = 0;
	}
	if (check_ret == -1)
	{
		current = current->prev;
		delete_from_grid(grid, *current);
		if (current->prev == NULL)
			return (-1);
		if (index_x < (size - 1))
			return (check_all_tetriminos(grid, current, current->grid_y, current->grid_x + 1));
		else
			return (check_all_tetriminos(grid, current, current->grid_y + 1, 0));
	}
	return (check_all_tetriminos(grid, current, index_y, index_x));
}


/**
 * @param size
 * MAKE THIS RECURSIIVE AND RETURN THE CORRECT THE RETURN STATEMENTS ON THE RIGHT TIME.
 * AND INCREASE THE INDEX_Y AND INDEX_X everytime it does not fit at the specific index.
 * @return -1 = Checked the entire grid, 0 = doesn't fit on specific index, 1 = fits.
 * Y = vertical - line number
 * X = horizontal - on the line
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
		if (index_y + current.y[y] >= size || (index_x + current.x[x] >= size && index_y >= size)) {
			return (-1);
		}
		if (grid[index_y + current.y[y]][index_x + current.x[x]] != '.') {
			return (0);
		}
		x++;
		y++;
	}
	printf("CHECK: '%c' index_y: %d, index_x: %d\n", current.letter, index_y, index_x);
	return (add_to_grid(grid, current, index_y, index_x));
}

/**
 * Subtracts the coordinates so that both X and Y
 * are decreased to the most upleft top, eliminating all the unused coordinates.
 * @Formula: find the lowest X or Y coordinate and decrease all the coords by the lowest.
 *
 * 	EXAMPLE:
 *    2,2	becomes		0, 1
 *    3,1	becomes		1, 0
 *    3,2	becomes		1, 1
 *    3,3	becomes		1, 2
 */
void		subtractCoordinates(t_tetrimino *head, int check)
{
	t_tetrimino *current;
	int lowest;
	int index;
	int *coords;

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
		subtractCoordinates(head, 0);
}

