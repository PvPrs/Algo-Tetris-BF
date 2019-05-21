/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validator.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-boc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 20:11:53 by dvan-boc      #+#    #+#                 */
/*   Updated: 2019/05/21 20:11:57 by dvan-boc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** Checks if the tetrimino's are valid and
** if each Tetrimino Block touches atleast another block.
** Check if the read '#' tetrimino block has any adjacent blocks,
** if not, we can discard the tetrimino.
** @return 0 = Valid tetrimino set, -1 is invalid tetrimino set
** @param buf represents the string containing the tetrimino sample set.
*/

int			ft_validator(char *buf, int blocks, int adjacent, int dots)
{
	int index;

	index = 0;
	while (buf[index])
	{
		if ((buf[index] != '#' && buf[index] != '.' && buf[index] != '\n'))
			return (-1);
		if (buf[index] == '#')
		{
			blocks++;
			if (buf[index - 1] == '#')
				adjacent++;
			if (buf[index + 1] == '#')
				adjacent++;
			if (buf[index + 5] == '#')
				adjacent++;
			if (buf[index - 5] == '#')
				adjacent++;
		}
		buf[index] != '.' || dots++;
		index++;
	}
	if (adjacent != 6 || blocks != 4 || dots != 12)
		return (-1);
	return (0);
}
