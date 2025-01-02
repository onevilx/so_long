/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:12:18 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/02 23:21:05 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_coin_frames(char *frames[])
{
	frames[0] = "textures_bonus/anim_coin/coin01.xpm";
	frames[1] = "textures_bonus/anim_coin/coin02.xpm";
	frames[2] = "textures_bonus/anim_coin/coin03.xpm";
	frames[3] = "textures_bonus/anim_coin/coin04.xpm";
	frames[4] = "textures_bonus/anim_coin/coin06.xpm";
	frames[5] = "textures_bonus/anim_coin/coin07.xpm";
	frames[6] = "textures_bonus/anim_coin/coin08.xpm";
	frames[7] = "textures_bonus/anim_coin/coin09.xpm";
	frames[8] = NULL;
}

void	set_enemy_frames(char *frames[])
{
	frames[0] = "textures_bonus/enemy_anim/idle_01.xpm";
	frames[1] = "textures_bonus/enemy_anim/idle_02.xpm";
	frames[2] = "textures_bonus/enemy_anim/idle_03.xpm";
	frames[3] = "textures_bonus/enemy_anim/idle_04.xpm";
	frames[4] = "textures_bonus/enemy_anim/idle_05.xpm";
	frames[5] = "textures_bonus/enemy_anim/idle_06.xpm";
	frames[6] = "textures_bonus/enemy_anim/idle_07.xpm";
	frames[7] = "textures_bonus/enemy_anim/idle_08.xpm";
	frames[8] = NULL;
}
