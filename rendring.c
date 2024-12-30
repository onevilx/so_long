/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:05:34 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/29 16:03:17 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_function(t_info *pic)
{
	free(pic);
	exit(0);
}

void	render(char *map)
{
	t_info	*pic;
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (write(1, "Error!\n fix render!", 20), free(map), exit(1));
	pic = malloc(sizeof(t_info));
	if (!pic)
		return (free(map), exit (1));
	pic->rows = ft_split(map, '\n');
	pic->movesh = 1;
	free(map);
	fetch_pic(pic, mlx_ptr);
	render_background(pic->rows, pic);
	render_wall(pic->rows, pic);
	render_door(pic->rows, pic);
	render_hero(pic->rows, pic);
	render_coin(pic->rows, pic);
	mlx_hook(pic->mlx_window, 2, 0, ft_buttons, pic);
	mlx_hook(pic->mlx_window, 17, 0, clean_function, pic);
	mlx_loop(pic->mlx_ptr);
}
