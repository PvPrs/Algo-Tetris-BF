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

#include "fillit.h"

/**
 * The purpose of sort_list is to sort the 2D Array into a sorted list of tetrimino's
 * Each tetrimino should be able to identify as a valid tetrimino.
 * @param buf A 2D Array containing the read Tetrimino's
 * @return Return 0 for succesfully sorted list, return -1 for invalid tetrimino's
 */
int		ft_sort_list(char **buf)
{
	int t_index;
	int index;
	int x;
	int block;
	t_tetrimino curr;

	block = 0;
	x = 0;
	t_index = 0;
	index = 0;
	while (buf[t_index][0] != '\0')
	{
		if (ft_validator(buf[t_index]) == -1)
			return (-1);
		while (buf[t_index][index])
		{
			if (buf[t_index][index] == '\n' && index != 19)
			{
				curr.y[block]++;
				x = 0;
			}
			if (buf[t_index][index] == '#')
			{
				curr.x[block] = x;
				block++;
			}
			index++;
			x++;
		}
		t_index++;
	}
	return (0);
}