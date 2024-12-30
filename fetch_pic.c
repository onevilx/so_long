/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_pic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:16:47 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/29 17:09:32 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_window(t_info *pic, void *mlx_ptr, char **rows)
{
	pic->mlx_ptr = mlx_ptr;
	pic->mlx_window = mlx_new_window(pic->mlx_ptr,
			pic->pic_width * check_col_len(*rows),
			pic->pic_height * check_len_rows(rows), "so long");
	if (!(pic->mlx_window))
	{
		write(1, "Error\n can't open the window!", 30);
		free(pic);
		exit (1);
	}
}
t_info	fetch_pic(t_info *pic, void *mlx_ptr)
{
	char	**rows;

	rows = pic->rows;
	pic->mlx_ptr = mlx_ptr;
	get_background(pic, mlx_ptr);
	get_wall(pic, mlx_ptr);
	get_closeddoor(pic, mlx_ptr);
	get_opendoor(pic, mlx_ptr);
	load_coin_animation(pic, mlx_ptr);
	load_hero_animation(pic, mlx_ptr);
	load_enemy_animation(pic, mlx_ptr);
	open_window(pic, mlx_ptr, rows);
	return (*pic);
}
