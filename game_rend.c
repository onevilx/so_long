/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:03:05 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/30 22:54:05 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rendersize_wall(char **rows, t_info *pic)
{
	size_t	m;
	size_t	n;

	m = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == '1')
				mlx_put_image_to_window((pic)->mlx_ptr,
					(pic)->mlx_window, (pic)->pic_wall, n * 75, m * 75);
			n++;
		}
		m++;
	}
}

void	rendersize_character(char **rows, t_info *pic)
{
	size_t	m;
	size_t	n;

	m = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'P')
			{
				mlx_put_image_to_window((pic)->mlx_ptr,
					(pic)->mlx_window, (pic)->pic_character, n * 75, m * 75);
				break ;
			}
			n++;
		}
		m++;
	}
}

void	rendersize_coin(char **rows, t_info *pic)
{
	size_t	m;
	size_t	n;

	m = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'C')
				mlx_put_image_to_window((pic)->mlx_ptr,
					(pic)->mlx_window, (pic)->pic_coin, n * 75, m * 75);
			n++;
		}
		m++;
	}
}

void	rendersize_door(char **rows, t_info *pic)
{
	size_t	m;
	size_t	n;

	m = 0;
	while (rows[m])
	{
		n = 0;
		while (rows[m][n])
		{
			if (rows[m][n] == 'E')
			{
				mlx_put_image_to_window((pic)->mlx_ptr,
					(pic)->mlx_window, pic->pic_closeddoor, n * 75, m * 75);
				break ;
			}
			n++;
		}
		m++;
	}
}

void	rendersize_background(char **rows, t_info *pic)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (rows[i])
	{
		j = 0;
		while (rows[i][j])
		{
			mlx_put_image_to_window((pic)->mlx_ptr,
				(pic)->mlx_window, (pic)->pic_background, j * 75, i * 75);
			j++;
		}
		i++;
	}
}
