/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buttons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:10:15 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/29 17:09:10 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	is_door_open(t_info *pic)
{
	char	**rows;
	int		b;

	rows = pic->rows;
	b = redeem_coins(rows);
	if (b == 0)
		ft_door(rows, pic);
}

int	ft_buttons(int button, void *p)
{
	t_info	*pic;

	pic = p;
	if (button == 13)
		up(p);
	else if (button == 0)
		left(p);
	else if (button == 1)
		down(p);
	else if (button == 2)
		right(p);
	else if (button == 53)
		exit(0);
	is_door_open(pic);
	return (0);
}

void	ren_again(t_info *pic, t_position coor, char **rows)
{
	mlx_put_image_to_window(pic->mlx_ptr,
		pic->mlx_window, pic->pic_background, coor.column * 75, coor.row * 75);
	if (rows[(coor.row)][coor.column] == 'E')
		mlx_put_image_to_window(pic->mlx_ptr,
			pic->mlx_window, pic->pic_closeddoor, coor.column * 75, coor.row * 75);
}
