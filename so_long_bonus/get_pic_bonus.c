/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pic_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:14 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/01 23:37:34 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_texture_closeddoor(t_infob *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_closeddoor = mlx_xpm_file_to_image(pic->mlx_ptr,
			"textures_bonus/game_textures/doorclosedb.xpm", &pic->pic_width, &pic->pic_height);
	if (!(pic->pic_closeddoor))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the doorclosed's image!", 34);
		free(pic);
		exit (1);
	}
}

void	get_texture_opendoor(t_infob *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_opendoor = mlx_xpm_file_to_image(pic->mlx_ptr,
			"textures_bonus/game_textures/dooropenb.xpm", &pic->pic_width, &pic->pic_height);
	if (!(pic->pic_opendoor))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the dooropen's image!", 32);
		free(pic);
		exit (1);
	}
}

void	get_texture_wall(t_infob *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_wall = mlx_xpm_file_to_image(pic->mlx_ptr,
			"textures_bonus/game_textures/wall_bonus.xpm",
				&pic->pic_width, &pic->pic_height);
	if (!(pic->pic_wall))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the wall's image!", 28);
		free(pic);
		exit (1);
	}
}

void	get_texture_background(t_infob *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_background = mlx_xpm_file_to_image(pic->mlx_ptr,
			"textures_bonus/game_textures/backgroundb.xpm", &pic->pic_width, &pic->pic_height);
	if (!(pic->pic_background))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the background's image!", 34);
		free(pic);
		exit (1);
	}
}

void	get_texture_coin(t_infob *pic, void *mlx_ptr)
{
	int	i;
	char	*frames[] = {
		"textures_bonus/anim_coin/coin01.xpm", "textures_bonus/anim_coin/coin02.xpm",
		"textures_bonus/anim_coin/coin03.xpm", "textures_bonus/anim_coin/coin04.xpm",
		"textures_bonus/anim_coin/coin06.xpm", "textures_bonus/anim_coin/coin07.xpm",
		"textures_bonus/anim_coin/coin08.xpm", "textures_bonus/anim_coin/coin09.xpm",
		NULL,
	};

	pic->mlx_ptr = mlx_ptr;
	pic->current_coin_frame = 0;
	i = 0;
	while (frames[i])
	{
		pic->pic_coin_frames[i] = mlx_xpm_file_to_image(pic->mlx_ptr,
			frames[i], &pic->pic_width, &pic->pic_height);
		if (!(pic->pic_coin_frames[i]))
		{
			write(1, "Error\ncan't get the coin's image!", 34);
			free(pic);
			exit (1);
		}
	i++;
	}
	pic->num_coin_frames = i;
}
