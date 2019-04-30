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
 */
char	*ft_solve(t_tetrimino *lst, char **grid)
{
	int index;
//	int gindex;

//	size = 4;
//	gindex = 9;
//
//	9 / 4 = 2;
//	9 % 4 = 1;
//	while gindex < size * size

	index = 0;
	while (index < 4)
	{
		grid[lst->y[index] + (gindex / size) ][lst->x[index] + (gindex % size)] = 'A';
		index++;
	}
	return (0);
}

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
	map = (char**)malloc(sq_root * sizeof(char *));
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
	return (map);
}

/**
 *
 * LIST, all the coordinates minus the lowest coordinate;
 *
 * 	lowest - lowest
 * 	EXAMPLE:
 *    2,2	0, 1
 *    3,1	1, 0
 *    3,2	1, 1
 *    3,3	1, 2
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

