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

/**
 * The purpose of sort_list is to sort the 2D Array into a sorted list of tetrimino's
 * Each tetrimino should be able to identify as a valid tetrimino.
 * @param buf A 2D Array containing the read Tetrimino's
 * @return Return 0 for succesfully sorted list, return -1 for invalid tetrimino's
 */
t_tetrimino		*ft_sort_list(char **buf)
{
	int t_index;
	int index;
	int x;
	int y;
	int block;
	char id;
	t_tetrimino *curr;
	t_tetrimino *head;
	char letter = 'A';

	block = 0;
	x = 0;
	y = 0;
	t_index = 0;
	index = 0;
	curr = (t_tetrimino*)malloc(sizeof(t_tetrimino));
	head = curr;
	while (buf[t_index])
	{
		if (ft_validator(buf[t_index]) == -1) {
			if (buf[t_index][0] == '\0')
			{
				free(curr);
				break;
			}
			return (NULL);
		}
		while (buf[t_index][index])
		{
			if (buf[t_index][index] == '\n' && index != 19)
			{
				y++;
				x = 0;
				index++;
				continue;
			}
			if (buf[t_index][index] == '#')
			{
				curr->x[block] = x;
				curr->y[block] = y;
				block++;
			}
			index++;
			x++;
		}
		curr->letter = letter;
		curr->next = (t_tetrimino*)malloc(sizeof(t_tetrimino));
		curr->next->prev = curr;
		curr = curr->next;
		id++;
		letter++;
		block = 0;
		x = 0;
		y = 0;
		index = 0;
		t_index++;
	}
	return (head);
}