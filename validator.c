//
// Created by Dave Van bochove on 2019-04-04.
//

#include "fillit.h"

/**
 * Checks if the tetrimino's are valid and if each Tetrimino Block touchest atleast another block.
 * Check if the read '#' tetrimino block has any adjacent blocks, if not, we can discard the tetrimino.
 * @return 0 = Valid tetrimino set, -1 is invalid tetrimino set
 * @param buf represents the string containing the tetrimino sample set.
 */
int ft_validator(char *buf)
{
	int index = 0;
	int blocks = 0;
	int adjacent = 0;
	int dots = 0;

	dots = 0;
	index = 0;
	blocks = 0;
	adjacent = 0;
	while (buf[index])
	{
		if ((buf[index] != '#' && buf[index] != '.' && buf[index] != '\n') || ft_strlen(buf) != 21)
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
		if (buf[index] == '.')
			dots++;
		index++;
	}
	if (adjacent != 6 || blocks != 4 || dots != 12)
		return (-1);
	return (0);
}