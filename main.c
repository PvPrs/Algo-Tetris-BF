/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-boc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 03:03:39 by dvan-boc      #+#    #+#                 */
/*   Updated: 2019/03/15 03:03:42 by dvan-boc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** DEFGROUP
** T_SIZE represents the maximum amount of tetrimino's
** BUFF_SIZE represents the maximum amount of bits read
*/
#define T_SIZE 26
#define BUFF_SIZE 16

/**
 *
 * @param argc Counts the amount of arguments given, default is 1.
 * @param argv Represents the filename to read.
 * @return Returns an int {0} on completion.
 * The purpose of the tetrimino's is to find the smallest
 * possible solution to the smallest possible square.
 *
 * @reader read the given file and store each tetrimino in a multi_dimensional array @link#main -> buf[tetrimino_id][read_bits].
 * @sort_list sort the Multi_dimensional_array into a list containing the ID, and each #'s coordinate {X, Y}
 * @solver Find the smallest possible solution to a {x * x} sided square ignoring holes with the stored tetriminos
 */
int		main(int argc, char **argv)
{
	char buf[T_SIZE][BUFF_SIZE];

	if (argc != 2)
	{
		ft_putendl("USAGE: fillit [FILE]");
		return (0);
	}
	ft_read(argv[0], buf);
}
