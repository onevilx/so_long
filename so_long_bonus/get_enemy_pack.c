/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_enemy_pack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:23:33 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/01 20:38:00 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	rendersize_enemy(char **rows, t_infob *pic)
{
	size_t	m;
	size_t	n;

	m = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'Y')
				mlx_put_image_to_window((pic)->mlx_ptr, (pic)->mlx_window,
					(pic)->pic_enemy_frames[pic->current_enemy_frame], n * 75, m * 75);
			n++;
		}
		m++;
	}
	pic->current_coin_frame = (pic->current_coin_frame + 1) % pic->num_coin_frames;
}
void	get_texture_enemy(t_infob *pic, void *mlx_ptr)
{
	int		i;
	char	*frames[] = {
		"textures_bonus/enemy_anim/idle_01.xpm", "textures_bonus/enemy_anim/idle_02.xpm",
		"textures_bonus/enemy_anim/idle_03.xpm", "textures_bonus/enemy_anim/idle_04.xpm",
		"textures_bonus/enemy_anim/idle_05.xpm", "textures_bonus/enemy_anim/idle_06.xpm",
		"textures_bonus/enemy_anim/idle_07.xpm", "textures_bonus/enemy_anim/idle_08.xpm",
		NULL
	};
	pic->mlx_ptr = mlx_ptr;
	pic->current_enemy_frame = 0;
	i = 0;
	while (frames[i])
	{
		pic->pic_enemy_frames[i] = mlx_xpm_file_to_image(pic->mlx_ptr,
			frames[i], &pic->pic_width, &pic->pic_height);
		if (!(pic->pic_enemy_frames[i]))
		{
			write(1, "Error!\n can't get the enemy's image!", 37);
			free(pic);
			exit(1);
		}
		i++;
	}
	pic->num_enemy_frames = i;
}
