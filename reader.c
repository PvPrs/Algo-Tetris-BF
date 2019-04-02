/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-boc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 03:03:54 by dvan-boc      #+#    #+#                 */
/*   Updated: 2019/03/15 03:03:57 by dvan-boc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

/**
 *
 * @param file represents the file name to be read.
 * @return returns an integer
 * Reads a file containing multiple tetrmino's ranging from 1 to 26 tetrimino's
 * Every # is recognized as a Tetrimino_Block and every . is ignored
 * @PURPOSE:
 * The purpose of the tetrimino's is to find the smallest
 * possible solution to the smallest possible square
 *
 * EXAMPLE:
 * Coords start at 0, 0 and end at 4, 4
 */

int		ft_read(const char *file, char **buf)
{
	int fd;
	int t_index;
	int ret;

	t_index = 0;
	ret = 1;
	fd = open(file, O_RDONLY);
	while (ret != EOF && t_index < 26)
	{
		buf[t_index] = malloc(BUFF_SIZE * sizeof(buf));
		ret = read(fd, buf[t_index], 21);
		t_index++;
	}
	return (0);
}
