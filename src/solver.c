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
#include <stdio.h>
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
	while (check_all_tetr(grid, current, 0, 0) == -1)
		grid = ft_grid_gen(ft_strlen(grid[0]) + 1);
	while (grid[i] != NULL)
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
		i++;
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

int			check_all_tetr(char **grid, t_tetrimino *curr, int ind_y, int ind_x)
{
	static int tries = 0;
	int size;
	int check_ret;

	size = ft_strlen(grid[0]) - 1;
	int index = 0;
	printf("curr: %c, y:%d, x:%d\n", curr->letter, ind_y, ind_x);
	while (index < size)
		printf("%s\n", grid[index++]);
	printf("Final\n");
	tries++;
	printf("tries: %d\n", tries);
	if (tries == 47630)
		getchar();
	printf("%p\n", &curr);
	check_ret = check_tetrimino(grid, *curr, ind_y, ind_x);
	//printf("after check_ret\n");
	if (check_ret == 0) {
		(ind_x < (size - 1)) ? ++ind_x : ++ind_y && (ind_x = 0);
		//printf("got here \n");
	}
	if (check_ret == 1)
	{
		if (!(curr->next->letter > 'A' && curr->next->letter < 'Z'))
			return (1);
		assign_curr(&curr, &ind_y, &ind_x);
	}
	if (check_ret == -1)
	{
		if (curr->prev == NULL)
		{
			delete_from_grid(grid, *curr);  // this needs fixing for specific combinations, check 42 filechecker
			return (-1);
		}
		curr = curr->prev != NULL ? curr->prev : curr;
		delete_from_grid(grid, *curr);
		return (ind_x < (size - 1) ?
				check_all_tetr(grid, curr, curr->grid_y, curr->grid_x + 1) :
				check_all_tetr(grid, curr, curr->grid_y + 1, 0));
	}
	//printf("%c, y:%d, x:%d\n", curr->letter, ind_y, ind_x);
	return (check_all_tetr(grid, curr, ind_y, ind_x));
}

/*
** assigns the current node coordinates, and continues to next
** Resets the coordinates.
** @param curr
** @param ind_y
** @param ind_x
*/

void		assign_curr(t_tetrimino **curr, int *ind_y, int *ind_x)
{
	t_tetrimino	*node;

	node = *curr;
	node->grid_x = *ind_x;
	node->grid_y = *ind_y;
	*curr = node->next;
	*ind_x = 0;
	*ind_y = 0;
}

/*
** Checks a single Tetrimino.
** @return -1 = Checked the entire grid
** @return 0 = doesn't fit on specific index
** @return 1 = fits.
** Y = vertical - line number
** X = horizontal - on the line
*/

int			check_tetrimino(char **grid, t_tetrimino curr, int ind_y, int ind_x)
{
	int y;
	int x;
	int size;

	size = (int) ft_strlen(grid[0]) - 1;
	printf("gets strlen: %d\n", size);
	x = 0;
	y = 0;
	while (x < 4)
	{
		if (ind_y + curr.y[y] >= size ||
		(ind_x + curr.x[x] >= size && ind_y >= size)){
			printf("%c checked entire grid.\n", curr.letter);
			return (-1);}
		if (grid[ind_y + curr.y[y]][ind_x + curr.x[x]] != '.') {
			printf("%c doesn't fit on y:%d, x:%d, size: %d.\n", curr.letter, ind_y, ind_x, size);
			return (0);}
		printf("Looped through again.\n");
		x++;
		y++;
	}
	printf("%c fit on y:%d, x:%d.\n", curr.letter, ind_y, ind_x);
	return (add_to_grid(grid, curr, ind_y, ind_x));
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
