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

#include "fillit.h"

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
char	*ft_solve(t_tetrimino *lst)
{
	while (lst->next != NULL)
	{
		printf("\n\n SOLVER: ");
		printf("1: x: %d, y: %d\n", lst->x[0], lst->y[0]);
		printf("2: x: %d, y: %d\n", lst->x[1], lst->y[1]);
		printf("3: x: %d, y: %d\n", lst->x[2], lst->y[2]);
		printf("4: x: %d, y: %d\n", lst->x[3], lst->y[3]);
		lst = lst->next;
	}
	return (0);
}

char