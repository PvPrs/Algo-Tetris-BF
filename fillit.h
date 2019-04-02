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

/*
** @struct Typedef = tetrimino
** X, represents the horizontal coordinate of the 4x4 block
** Y, represents the vertical coordinate of the 4x4 block
** ID, represents the tetrimino ID.
*/

typedef struct
{
	int x[4];
	int y[4];
	int id;
	t_tetrimino *next;
}		t_tetrimino;

int		ft_read(char *file);

#endif //FILLIT_FILLIT_H
