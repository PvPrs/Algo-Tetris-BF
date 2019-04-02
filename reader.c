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

/**ß
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
 *          ....
 *          ....
 *          ....
 *          ....
 */
int		ft_read(const char *file, char **buf)
{ß
	int fd;
	int curr;

	fd = open(file, O_RDONLY);
	buf = malloc(sizeof())
	read()
	current = tetrimino.next;
	current = {.id = 1, .x[1] = 0};
}
