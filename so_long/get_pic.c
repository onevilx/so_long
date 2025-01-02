/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:14 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/31 01:39:32 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_texture_closeddoor(t_info *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_closeddoor = mlx_xpm_file_to_image(pic->mlx_ptr,
			"textures/doorclosed.xpm", &pic->pic_width, &pic->pic_height);
	if (!(pic->pic_closeddoor))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the doorclosed's image!", 27);
		free(pic);
		exit (1);
	}
}

void	get_texture_opendoor(t_info *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_opendoor = mlx_xpm_file_to_image(pic->mlx_ptr,
			"textures/dooropen.xpm", &pic->pic_width, &pic->pic_height);
	if (!(pic->pic_opendoor))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the dooropen's image!", 25);
		free(pic);
		exit (1);
	}
}

void	get_texture_wall(t_info *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_wall = mlx_xpm_file_to_image(pic->mlx_ptr,
			"textures/wall.xpm", &pic->pic_width, &pic->pic_height);
	if (!(pic->pic_wall))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the wall's image!", 27);
		free(pic);
		exit (1);
	}
}

void	get_texture_background(t_info *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_background = mlx_xpm_file_to_image(pic->mlx_ptr,
			"textures/background.xpm", &pic->pic_width, &pic->pic_height);
	if (!(pic->pic_background))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the background's image!", 28);
		free(pic);
		exit (1);
	}
}

void	get_texture_coin(t_info *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_coin = mlx_xpm_file_to_image(pic->mlx_ptr,
			"textures/coin.xpm", &pic->pic_width, &pic->pic_height);
	if (!(pic->pic_coin))
	{
		write(1, "Error!\n", 7);
		write(1, "can't get the coin's image!", 29);
		free(pic);
		exit (1);
	}
}
