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

int			main(int argc, char **argv)
{
	t_tetrimino	*lst;
	char		**buf;
	int			size;

	lst = NULL;
	buf = ft_memalloc(26 * sizeof(char *));
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
	ft_shutdown(lst);
	return (0);
}

void		ft_shutdown(t_tetrimino *lst)
{
	t_tetrimino *temp;

	while (lst->next != NULL)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
	free(lst);
}
