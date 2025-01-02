/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_pic_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:02:25 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/01 18:41:36 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_texture_character(t_infob *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_character = mlx_xpm_file_to_image(pic->mlx_ptr,
			"textures_bonus/game_textures/character.xpm",
			&pic->pic_width, &pic->pic_height);
	if (!(pic->pic_character))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the charcater's image!", 33);
		free(pic);
		exit (1);
	}
}

void	open_window(t_infob *pic, void *mlx_ptr, char **rows)
{
	pic->mlx_ptr = mlx_ptr;
	pic->mlx_window = mlx_new_window(pic->mlx_ptr,
			pic->pic_width * check_col_lenmap(*rows),
			pic->pic_height * check_len_rowsmap(rows), "so_long_bonus");
	if (!(pic->mlx_window))
	{
		write(1, "Error\n can't open the window!", 30);
		free(pic);
		exit (1);
	}
}

t_infob	fetch_pic(t_infob *pic, void *mlx_ptr)
{
	char	**rows;

	rows = pic->rows;
	pic->mlx_ptr = mlx_ptr;
	get_texture_background(pic, mlx_ptr);
	get_texture_wall(pic, mlx_ptr);
	get_texture_closeddoor(pic, mlx_ptr);
	get_texture_opendoor(pic, mlx_ptr);
	get_texture_coin(pic, mlx_ptr);
	get_texture_character(pic, mlx_ptr);
	get_texture_enemy(pic, mlx_ptr);
	open_window(pic, mlx_ptr, rows);
	return (*pic);
}
