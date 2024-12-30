/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:24:53 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/29 17:14:56 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moving(t_position coor, t_info *pic, char **rows, int btn)
{
	ft_printf("%d\n", pic->movesh);
	pic->movesh++;
	if (rows[(coor.row) - 1][coor.column] == 'X' && btn == 13)
		return (write(1, "The Outbreak Begins!\n", 22), free(pic), exit (0));
	else if (rows[(coor.row) + 1][coor.column] == 'X' && btn == 1)
		return (write(1, "The Outbreak Begins!\n", 22), free(pic), exit (0));
	else if (rows[coor.row][(coor.column) + 1] == 'X' && btn == 2)
		return (write(1, "The Outbreak Begins!\n", 22), free(pic), exit (0));
	else if (rows[coor.row][(coor.column) - 1] == 'X' && btn == 0)
		return (write(1, "The Outbreak Begins!\n", 22), free(pic), exit (0));
}
void	up(t_info *pic)
{
	t_position	coor;
	char	**rows;

	rows = pic->rows;
	coor = ft_position(rows, 0);
	if (rows[(coor.row) - 1][coor.column] != '1')
	{
		ft_moving(coor, pic, rows, 13);
		if (!door_checker(rows))
			rows[coor.row][coor.column] = 'E';
		else
			rows[coor.row][coor.column] = '0';
		rows[(coor.row) - 1][coor.column] = 'P';
		ren_again(pic, coor, rows);
		mlx_put_image_to_window(pic->mlx_ptr, pic->mlx_window,
			pic->pic_hero_idle, coor.column * 75, (coor.row - 1) * 75);
	}
}
void	down(t_info *pic)
{
	t_position	coor;
	char	**rows;

	rows = pic->rows;
	coor = ft_position(rows, 0);
	if (rows[(coor.row) + 1][coor.column] != '1')
	{
		ft_moving(coor, pic, rows, 1);
		if (!door_checker(rows))
			rows[coor.row][coor.column] = 'E';
		else
			rows[coor.row][coor.column] = '0';
		rows[(coor.row) + 1][coor.column] = 'P';
		ren_again(pic, coor, rows);
		mlx_put_image_to_window(pic->mlx_ptr, pic->mlx_window,
			pic->pic_hero_idle, coor.column * 75, (coor.row + 1) * 75);
	}
}

void	left(t_info *pic)
{
	t_position	coor;
	char	**rows;

	rows = pic->rows;
	coor = ft_position(rows, 0);
	if (rows[coor.row][coor.column - 1] != '1')
	{
		ft_moving(coor, pic, rows, 0);
		if (!door_checker(rows))
			rows[coor.row][coor.column] = 'E';
		else
			rows[coor.row][coor.column] = '0';
		rows[coor.row][(coor.column) - 1] = 'P';
		ren_again(pic, coor, rows);
		mlx_put_image_to_window(pic->mlx_ptr, pic->mlx_window,
			pic->pic_hero_idle, (coor.column - 1) * 75, coor.row * 75);
	}
}

void	right(t_info *pic)
{
	t_position	coor;
	char	**rows;

	rows = pic->rows;
	coor = ft_position(rows, 0);
	if (rows[coor.row][coor.column + 1] != '1')
	{
		ft_moving(coor, pic, rows, 2);
		if (!door_checker(rows))
			rows[coor.row][coor.column] = 'E';
		else
			rows[coor.row][coor.column] = '0';
		rows[coor.row][(coor.column) + 1] = 'P';
		ren_again(pic, coor, rows);
		mlx_put_image_to_window(pic->mlx_ptr, pic->mlx_window,
			pic->pic_hero_run, (coor.column + 1) * 75, coor.row * 75);
	}
}
