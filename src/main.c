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

#include "../includes/fillit.h"

/*
**
** @param argc Counts the amount of arguments given, default is 1.
** @param argv Represents the filename to read.
** @return Returns an int {0} on completion.
** The purpose of the tetrimino's is to find the smallest
** possible solution to the smallest possible square.
**
** @reader read the given file and store each tetrimino in a multi_dimensional array @link#main -> buf[tetrimino_id][read_bits].
** @sort_list sort the Multi_dimensional_array into a list containing the ID, and each #'s coordinate {X, Y}
** @solver Find the smallest possible solution to a {x * x} sided square ignoring holes with the stored tetriminos
*/
int		main(int argc, char **argv)
{
	t_tetrimino	*lst;
	char		**buf;
	int			size;
	t_tetrimino *temp;

	lst = NULL;
	buf = ft_memalloc(T_SIZE * sizeof(*buf));
	if (argc != 2)
	{
		ft_putendl("USAGE: fillit [FILE]");
		return (0);
	}
	size = ft_read(argv[1], buf);
	lst = ft_sort_list(buf, 0, 0, 0);
	ft_free_array((void **)buf);
	if (lst == NULL || size < 0)
	{
		ft_putstr("error\n");
		exit(1);
	}
	else
		ft_solve(lst, size);
	while (lst->next != NULL)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
	free(lst);
}