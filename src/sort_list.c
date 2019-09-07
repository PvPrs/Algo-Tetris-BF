/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-boc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 19:56:54 by dvan-boc      #+#    #+#                 */
/*   Updated: 2019/03/28 19:57:10 by dvan-boc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** The purpose of sort_list is to sort the 2D Array
** into a sorted list of tetrimino's. Each tetrimino
** should be able to identify as a valid tetrimino.
** @param buf A 2D Array containing the read Tetrimino's
** @return 0 for succesfully sorted list
** @return -1 for invalid tetrimino's
*/

t_tetrimino		*ft_sort_list(char **buf, int x, int y, int block)
{
	t_tetrimino	*curr;
	t_tetrimino	*head;
	int			index;

	index = 0;
	curr = ft_memalloc(sizeof(*curr));
	head = curr;
	while (*buf != NULL)
	{
		if (ft_validator(*buf, 0, 0, 0) == -1)
			return (NULL);
		while ((*buf)[index] != '\0')
		{
			if ((*buf)[index] == '#')
				set_coords(&curr, &block, x, y);
			ft_next_pos((*buf)[index], &index, &y, &x);
		}
		set_tetr_properties(&curr);
		reset_vars(&block, &x, &y, &index);
		buf++;
	}
	return (head);
}

void			ft_next_pos(char pos, int *index, int *y, int *x)
{
	if (pos == '\n' && *index != 19)
	{
		*y += 1;
		*x = 0;
	}
	else
		*x += 1;
	*index += 1;
}

void			set_coords(t_tetrimino **curr, int *block, int x, int y)
{
	t_tetrimino *node;

	node = *curr;
	node->x[*block] = x;
	node->y[*block] = y;
	*block += 1;
}

/*
** Resets all the variables of ft_sort_list
** @param block pointer to block var
** @param x pointer to x var
** @param y pointer to y var
** @param index pointer to index var
*/

void			reset_vars(int *block, int *x, int *y, int *index)
{
	*index = 0;
	*y = 0;
	*x = 0;
	*block = 0;
}

/*
** Addition to ft_sort_list, Adjusts the passed node to its desired completion.
** @param curr pointer to the node of curr
** @param flag
*/

void			set_tetr_properties(t_tetrimino **curr)
{
	static char letter = 'A';
	t_tetrimino *node;

	node = *curr;
	node->letter = letter;
	node->next = ft_memalloc(sizeof(*node));
	letter++;
	*curr = node->next;
}
