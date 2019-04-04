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
	int id;
	int x;
	int block;
	t_tetrimino curr;

	block = 0;
	x = 0;
	id = 1;
	t_index = 0;
	index = 0;
	while (buf[t_index][0] != '\0')
	{
		printf("Tetrimino: \n");
		printf("%s", buf[t_index]);
		if (ft_check_validity(buf[t_index]) == -1)
		{
			printf("incorrect tetrimino: %d\n ", t_index);
			return (-1);
		}
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
/**
 * Checks if the tetrimino's are valid and if each Tetrimino Block touchest atleast another block.
 * Check if the read '#' tetrimino block has any adjacent blocks, if not, we can discard the tetrimino.
 * @return 0 = Valid tetrimino set, -1 is invalid tetrimino set
 * @param buf represents the string containing the tetrimino sample set.
 */
int ft_check_validity(char *buf)
{
	int index;
	int index_2;

	index_2 = 0;
	index = 0;
	while (buf[index])
	{
		if (buf[index] == '#')
		{
			index_2 = index + 1;
			while (buf[index_2])
			{
				if (buf[index_2] == '#')
				{
					if ((index_2 - index) != 1 && (index_2 - index) != 5) {
						printf("index_2 - index = %d", index_2 - index);
						return (-1);
					}
					index = index_2;
				}
				index_2++;
			}
		}
		index++;
	}
	return (0);
}
//int		ft_check_validity(char *buf)
//{
//	int index;
//	int last_index;
//	index = 0;
//	if (buf[20] != '\n')
//	{
//		printf("index 20 != \\n, index 20: %c", buf[20]);
//		return (-1);
//	}
//	while (buf[index])
//	{
//		if (buf[index] == '#')
//		{
//			if (buf[index + 1] != '#' && buf[index - 1] != '#' && buf[index + 5] != '#' && buf[index - 5] != '#')
//			{
//				printf("incorrect index: %d char:%c\n", index, buf[index]);
//				return (-1);
//			}
//			last_index
//		}
//		index++;
//	}
//	return (0);
//}