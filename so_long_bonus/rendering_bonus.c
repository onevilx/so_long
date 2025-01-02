/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:29 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/02 00:45:48 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	clean_function(t_infob *pic)
{
	free(pic);
	exit(0);
}
void	delay(int milliseconds)
{
	int	counter = 0;
	while (counter < milliseconds * 100000)
		counter++;
}

int	render_animation(t_infob *pic)
{
	static int	frame = 0;

	frame++;
	if (frame % 10 == 0)
	{
		delay(666);
		pic->current_enemy_frame = (pic->current_enemy_frame + 1) % pic->num_enemy_frames;
		rendersize_enemy(pic->rows, pic);

		pic->current_coin_frame = (pic->current_coin_frame + 1) % pic->num_coin_frames;
		rendersize_coin(pic->rows, pic);
	}

	char *step_str = ft_itoa(pic->move);
	if (!step_str)
		return (1);
	mlx_string_put(pic->mlx_ptr, pic->mlx_window, 10, 30, 0xFF0000, step_str); // Display the updated step count
	free(step_str);
	return (0);
}


void	ft_rendering(char *map)
{
	t_infob	*pic;
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (write(1, "Error!\n fix render!", 20), free(map), exit(1));
	pic = malloc(sizeof(t_infob));
	if (!pic)
		return (free(map), exit (1));
	pic->rows = ft_split(map, '\n');
	pic->move = 1;
	free(map);
	fetch_pic(pic, mlx_ptr);
	rendersize_background(pic->rows, pic);
	rendersize_wall(pic->rows, pic);
	rendersize_door(pic->rows, pic);
	rendersize_character(pic->rows, pic);
	rendersize_enemy(pic->rows, pic);
	rendersize_coin(pic->rows, pic);
	mlx_hook(pic->mlx_window, 2, 0, ft_keycodes, pic);
	mlx_hook(pic->mlx_window, 17, 0, clean_function, pic);
	mlx_loop_hook(pic->mlx_ptr, render_animation, pic);
	mlx_string_put(pic->mlx_ptr, pic->mlx_window, 10, 10, 0xFF0000, "Steps: ");
	mlx_loop(pic->mlx_ptr);
}
