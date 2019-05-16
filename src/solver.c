/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dvan-boc <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/02 16:40:44 by dvan-boc      #+#    #+#                 */
/*   Updated: 2019/04/02 16:40:45 by dvan-boc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "stdlib.h"

/**
 * Find the smallest possible square with holes to
 * Each tetrimino must be placed in specific order starting from Tetrimino 'A' until the last set.
 * A maximum of 26 Tetrimino's are allowed.
 *
 * Algorithm:
 * First we place Tetrimino set 'A', in the most upleft corner.
 * Next we place set 'B', if it does not fit, we move The previous one, until 'B' fits.
 * Once 'B' fits, we continue to 'C', if 'C' doesn't fit we move around 'B' until it fits,
 * SCENARIO: It just doesn't fit! We start moving around 'A' again, Followed by 'B' until 'C' fits.
 *
 * @return a string forming a solved set of Tetrimino's
 * 			AABD\n
 * 			AABD\n
 * 			CCBD\n
 * 			CCBD\n
 *
 * 			check if 'a' fits, if 'a' fits, check if Return ((recursive func)current->next fits),
 * 			if it fits, check if the next Return ((recursive func)current->next fits), if ret == 1 succeed.
 *
 */

//void	ft_solve(t_tetrimino *head, char ***grid, int size)
//{
//	t_tetrimino	*current;
//	int ret;
//	int index_y;
//	int index_x;
//
//	current = head;
//
//	index_x = 0;
//	index_y = 0;
//	while (current->next != NULL)
//	{
//		printf("%d\n", size);
//		printf("index_y: %d, index_x: %d\n", index_y, index_x);
//		ret = check_all_tetriminos(grid, current, index_y, index_x);
//		if (ret == -1)
//		{
//			return (0);
////			printf("GETS HERE2!\n");
////			size = ft_strlen(*grid[0]);
////			printf("GRID ADR3: %p\n", grid);
////			clear_grid(*grid);
////			printf("GRID ADR4: %p\n", grid);
////			getchar();
////			printf("grid: %s\n", *grid[0]);
////			*grid = ft_grid_gen(size + 1); // GETS SEGFAULT "AFTER" CREATION OF NEW GRID CAUSED by Assigning MALLOCED SPACE, to a function used to malloc the grid!
////			index_x = 0;
////			index_y = 0;
////			current = head;
//		}
//		if (ret == 1)
//		{
//			current = current->next;
//			index_y++;
//			if (index_y == size - 1)
//				index_x++;
//		}
//	}
//	int index = 0;
////	while (index < size)
////	{
////		printf("%s\n", grid[index]);
////		index++;
////	}
//}

/**
 * @param size
 * MAKE THIS RECURSIIVE AND RETURN THE CORRECT THE RETURN STATEMENTS ON THE RIGHT TIME.
 * AND INCREASE THE INDEX_Y AND INDEX_X everytime it does not fit at the specific index.
 * @return -1 = Checked the entire grid, 0 = doesn't fit on specific index, 1 = fits.
 * Y = vertical - line number
 * X = horizontal - on the line
 */

int		check_all_tetriminos(char **grid, t_tetrimino *current, int index_y, int index_x)
{
    int size;
    int ret;
    int y = 0;
    while (grid[y] != NULL)
    {
        printf("%s\n", grid[y]);
        y++;
    }
    printf("\n");
    size = ft_strlen(grid[0]);


    ret = check_tetrimino(grid, *current, index_y, index_x);
    if (ret == 0)
    {
        printf("RETURN: %d, %c Does not fit on index Y:%d, X:%d\n", ret, current->letter, index_y, index_x);
        printf("'%c' on grid: x:%d, y:%d", current->letter, current->grid_y, current->grid_y);
        if (index_x < (size - 1))
            ++index_x;
        else
        {
            ++index_y;
            index_x = 0;
        }
    }
    if (ret == 1)
    {
        printf("RETURN: %d, Succes! %c Fits on index: Y:%d, X:%d\n", ret, current->letter, index_y, index_x);
        printf("'%c' on grid: x:%d, y:%d", current->letter, current->grid_y, current->grid_y);
        if (current->next == NULL)
            return (1);
        current = current->next;
        index_x = 0;
        index_y = 0;
    }
    if (ret == -1) // delete previous tetrimino, and try again, if 'A ' reaches end of grid, return -1 to increase grid size
    {
        printf("RETURN: %d\n", ret);
        return (-1);
    }
    getchar();

    while (check_all_tetriminos(grid, current, index_y++, index_x++) == -1)
    {
        getchar();
        printf("ret -1_in_loop: %c index_y: %d, index_x: %d\n", current->letter, index_y, index_x);
        current = current->prev;
        delete_from_grid(grid, *current);
        index_y = current->grid_y;
        index_x = current->grid_x;
    }
    printf("ret 3: index_y: %d, index_x: %d\n", index_y, index_x);
    getchar();
    return (check_all_tetriminos(grid, current, index_y, index_x));
}


/**
 * @param size
 * MAKE THIS RECURSIIVE AND RETURN THE CORRECT THE RETURN STATEMENTS ON THE RIGHT TIME.
 * AND INCREASE THE INDEX_Y AND INDEX_X everytime it does not fit at the specific index.
 * @return -1 = Checked the entire grid, 0 = doesn't fit on specific index, 1 = fits.
 * Y = vertical - line number
 * X = horizontal - on the line
 */


int		check_tetrimino(char **grid, t_tetrimino current, int index_y, int index_x)
{
	int y;
	int x;
	int size;
	size = strlen(grid[0]);
	x = 0;
	y = 0;

	while (x < 4)
	{
		if (index_y + current.y[y] >= size) {
			return (-1);
		}
		if (grid[index_y + current.y[y]][index_x + current.x[x]] != '.') {
			return (0);
		}
		x++;
		y++;
	}
	printf("'%c' index_y: %d\n", current.letter, index_y);
	current.grid_y = index_y;
	current.grid_x = index_x;
	return (add_to_grid(grid, current, index_y, index_x));
}

/**
 * Subtracts the coordinates so that both X and Y
 * are decreased to the most upleft top, eliminating all the unused coordinates.
 * @Formula: find the lowest X or Y coordinate and decrease all the coords by the lowest.
 *
 * 	EXAMPLE:
 *    2,2	becomes		0, 1
 *    3,1	becomes		1, 0
 *    3,2	becomes		1, 1
 *    3,3	becomes		1, 2
 */
void		subtractCoordinates(t_tetrimino *head, int check)
{
	t_tetrimino *current;
	int lowest;
	int index;
	int *coords;

	current = head;
	while (current->next != NULL)
	{
		lowest = 2100;
		index = 0;
		coords = (check) ? current->x : current->y;
		while (index < 4)
		{
			lowest = (coords[index] < lowest) ? coords[index] : lowest;
			index++;
		}
		index = 0;
		while (index < 4)
		{
			coords[index] -= lowest;
			index++;
		}
		current = current->next;
	}
	if (check)
		subtractCoordinates(head, 0);
}

