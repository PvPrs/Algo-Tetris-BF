/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-boc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 18:42:11 by dvan-boc      #+#    #+#                 */
/*   Updated: 2019/03/28 18:42:14 by dvan-boc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H

#include "libft.h"
#include <stdio.h>

/*
** DEFGROUP
** T_SIZE represents the maximum amount of tetrimino's
** BUFF_SIZE represents the maximum amount of bits read
*/
#define T_SIZE 26
#define BUFF_SIZE 21

/*
** @struct Typedef = tetrimino
** X, represents the horizontal coordinate of the 4x4 block
** Y, represents the vertical coordinate of the 4x4 block
** ID, represents the tetrimino ID.
*/

typedef struct	s_tetrimino
{
	int			x[4];
	int 		y[4];
	struct		s_tetrimino *next;
}				t_tetrimino;

int				ft_read(const char *file, char **buf);
t_tetrimino		*ft_sort_list(char **buf);
int				ft_validator(char *buf);
char			*ft_solve(t_tetrimino *lst);

#endif //FILLIT_FILLIT_H
