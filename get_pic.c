/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:15:01 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/29 18:15:27 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_closeddoor(t_info *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_closeddoor = mlx_xpm_file_to_image(pic->mlx_ptr, "textures/Exit/doorclosed.xpm",
			&pic->pic_width, &pic->pic_height);
	if (!(pic->pic_closeddoor))
	{
		write(1, "Error !\n can't get the closed door's image!", 44);
		free(pic);
		exit (1);
	}
}

void	get_opendoor(t_info *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_opendoor = mlx_xpm_file_to_image(pic->mlx_ptr, "textures/Exit/dooropen.xpm",
			&pic->pic_width, &pic->pic_height);
	if (!(pic->pic_opendoor))
	{
		write(1, "Error !\n can't get the open door's image!", 42);
		free(pic);
		exit (1);
	}
}

void	get_wall(t_info *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_wall = mlx_xpm_file_to_image(pic->mlx_ptr, "textures/Texturemap/wall.xpm",
			&pic->pic_width, &pic->pic_height);
	if (!(pic->pic_wall))
	{
		write(1, "Error !\n can't get the wall's image!", 37);
		free(pic);
		exit (1);
	}
}

void	get_background(t_info *pic, void *mlx_ptr)
{
	pic->mlx_ptr = mlx_ptr;
	pic->pic_background = mlx_xpm_file_to_image(pic->mlx_ptr, "textures/Texturemap/battleground.xpm",
			&pic->pic_width, &pic->pic_height);
	if (!(pic->pic_background))
	{
		write(1, "Error !\n can't get the background's image!", 37);
		free(pic);
		exit (1);
	}
}

void	load_coin_animation(t_info *pic, void *mlx_ptr)
{
	char	*coin_paths[9] = {
		"textures/coinAnimation/coin1.xpm", "textures/coinAnimation/coin2.xpm",
		"textures/coinAnimation/coin3.xpm", "textures/coinAnimation/coin4.xpm",
		"textures/coinAnimation/coin5.xpm", "textures/coinAnimation/coin6.xpm",
		"textures/coinAnimation/coin7.xpm", "textures/coinAnimation/coin8.xpm",
		"textures/coinAnimation/coin9.xpm"
	};
	int		i;

	i = 0;
	while (i < 9)
	{
		pic->pic_coin[i] = mlx_xpm_file_to_image(mlx_ptr, coin_paths[i],
				&pic->pic_width, &pic->pic_height);
		if (!pic->pic_coin[i])
		{
			write(1, "Error! Cannot load coin frame.\n", 31);
			exit(1);
		}
		i++;
	}
	pic->current_coin = 0;
}
void	load_enemy_animation(t_info *pic, void *mlx_ptr)
{
	// Idle Animation Paths
	char	*idle_paths[18] = {
		"textures/enemyAnimation/Idle/Idle00.xpm",
		"textures/enemyAnimation/Idle/Idle01.xpm",
		"textures/enemyAnimation/Idle/Idle02.xpm",
		"textures/enemyAnimation/Idle/Idle03.xpm",
		"textures/enemyAnimation/Idle/Idle04.xpm",
		"textures/enemyAnimation/Idle/Idle05.xpm",
		"textures/enemyAnimation/Idle/Idle06.xpm",
		"textures/enemyAnimation/Idle/Idle07.xpm",
		"textures/enemyAnimation/Idle/Idle08.xpm",
		"textures/enemyAnimation/Idle/Idle09.xpm",
		"textures/enemyAnimation/Idle/Idle10.xpm",
		"textures/enemyAnimation/Idle/Idle11.xpm",
		"textures/enemyAnimation/Idle/Idle12.xpm",
		"textures/enemyAnimation/Idle/Idle13.xpm",
		"textures/enemyAnimation/Idle/Idle14.xpm",
		"textures/enemyAnimation/Idle/Idle15.xpm",
		"textures/enemyAnimation/Idle/Idle16.xpm",
		"textures/enemyAnimation/Idle/Idle17.xpm"
	};

	// Running Animation Paths
	char	*run_paths[12] = {
		"textures/enemyAnimation/Running/Run00.xpm",
		"textures/enemyAnimation/Running/Run01.xpm",
		"textures/enemyAnimation/Running/Run02.xpm",
		"textures/enemyAnimation/Running/Run03.xpm",
		"textures/enemyAnimation/Running/Run04.xpm",
		"textures/enemyAnimation/Running/Run05.xpm",
		"textures/enemyAnimation/Running/Run06.xpm",
		"textures/enemyAnimation/Running/Run07.xpm",
		"textures/enemyAnimation/Running/Run08.xpm",
		"textures/enemyAnimation/Running/Run09.xpm",
		"textures/enemyAnimation/Running/Run10.xpm",
		"textures/enemyAnimation/Running/Run11.xpm"
	};

	// Walking Animation Paths
	char	*walk_paths[24] = {
		"textures/enemyAnimation/Walking/Walking00.xpm",
		"textures/enemyAnimation/Walking/Walking01.xpm",
		"textures/enemyAnimation/Walking/Walking02.xpm",
		"textures/enemyAnimation/Walking/Walking03.xpm",
		"textures/enemyAnimation/Walking/Walking04.xpm",
		"textures/enemyAnimation/Walking/Walking05.xpm",
		"textures/enemyAnimation/Walking/Walking06.xpm",
		"textures/enemyAnimation/Walking/Walking07.xpm",
		"textures/enemyAnimation/Walking/Walking08.xpm",
		"textures/enemyAnimation/Walking/Walking09.xpm",
		"textures/enemyAnimation/Walking/Walking10.xpm",
		"textures/enemyAnimation/Walking/Walking11.xpm",
		"textures/enemyAnimation/Walking/Walking12.xpm",
		"textures/enemyAnimation/Walking/Walking13.xpm",
		"textures/enemyAnimation/Walking/Walking14.xpm",
		"textures/enemyAnimation/Walking/Walking15.xpm",
		"textures/enemyAnimation/Walking/Walking16.xpm",
		"textures/enemyAnimation/Walking/Walking17.xpm",
		"textures/enemyAnimation/Walking/Walking18.xpm",
		"textures/enemyAnimation/Walking/Walking19.xpm",
		"textures/enemyAnimation/Walking/Walking20.xpm",
		"textures/enemyAnimation/Walking/Walking21.xpm",
		"textures/enemyAnimation/Walking/Walking22.xpm",
		"textures/enemyAnimation/Walking/Walking23.xpm"
	};

	int	i;

	// Load Idle Frames
	i = 0;
	while (i < 18)
	{
		pic->pic_enemy_idle[i] = mlx_xpm_file_to_image(mlx_ptr, idle_paths[i],
				&pic->pic_width, &pic->pic_height);
		if (!pic->pic_enemy_idle[i])
		{
			write(1, "Error! Cannot load enemy idle frame.\n", 36);
			exit(1);
		}
		i++;
	}

	// Load Running Frames
	i = 0;
	while (i < 12)
	{
		pic->pic_enemy_run[i] = mlx_xpm_file_to_image(mlx_ptr, run_paths[i],
				&pic->pic_width, &pic->pic_height);
		if (!pic->pic_enemy_run[i])
		{
			write(1, "Error! Cannot load enemy run frame.\n", 35);
			exit(1);
		}
		i++;
	}

	// Load Walking Frames
	i = 0;
	while (i < 24)
	{
		pic->pic_enemy_walk[i] = mlx_xpm_file_to_image(mlx_ptr, walk_paths[i],
				&pic->pic_width, &pic->pic_height);
		if (!pic->pic_enemy_walk[i])
		{
			write(1, "Error! Cannot load enemy walking frame.\n", 39);
			exit(1);
		}
		i++;
	}

	pic->current_enemy = 0;
	pic->enemy_state = ENEMY_IDLE;
}
void	load_hero_animation(t_info *pic, void *mlx_ptr)
{
	// Idle Animation Paths
	char	*idle_paths[18] = {
		"textures/heroAnimation/Idle/Idle00.xpm",
		"textures/heroAnimation/Idle/Idle01.xpm",
		"textures/heroAnimation/Idle/Idle02.xpm",
		"textures/heroAnimation/Idle/Idle03.xpm",
		"textures/heroAnimation/Idle/Idle04.xpm",
		"textures/heroAnimation/Idle/Idle05.xpm",
		"textures/heroAnimation/Idle/Idle06.xpm",
		"textures/heroAnimation/Idle/Idle07.xpm",
		"textures/heroAnimation/Idle/Idle08.xpm",
		"textures/heroAnimation/Idle/Idle09.xpm",
		"textures/heroAnimation/Idle/Idle10.xpm",
		"textures/heroAnimation/Idle/Idle11.xpm",
		"textures/heroAnimation/Idle/Idle12.xpm",
		"textures/heroAnimation/Idle/Idle13.xpm",
		"textures/heroAnimation/Idle/Idle14.xpm",
		"textures/heroAnimation/Idle/Idle15.xpm",
		"textures/heroAnimation/Idle/Idle16.xpm",
		"textures/heroAnimation/Idle/Idle17.xpm"
	};

	// Running Animation Paths
	char	*run_paths[12] = {
		"textures/heroAnimation/running/Run00.xpm",
		"textures/heroAnimation/running/Run01.xpm",
		"textures/heroAnimation/running/Run02.xpm",
		"textures/heroAnimation/running/Run03.xpm",
		"textures/heroAnimation/running/Run04.xpm",
		"textures/heroAnimation/running/Run05.xpm",
		"textures/heroAnimation/running/Run06.xpm",
		"textures/heroAnimation/running/Run07.xpm",
		"textures/heroAnimation/running/Run08.xpm",
		"textures/heroAnimation/running/Run09.xpm",
		"textures/heroAnimation/running/Run10.xpm",
		"textures/heroAnimation/running/Run11.xpm"
	};

	// Dying Animation Paths
	char	*death_paths[15] = {
		"textures/heroAnimation/Dying/Death00.xpm",
		"textures/heroAnimation/Dying/Death01.xpm",
		"textures/heroAnimation/Dying/Death02.xpm",
		"textures/heroAnimation/Dying/Death03.xpm",
		"textures/heroAnimation/Dying/Death04.xpm",
		"textures/heroAnimation/Dying/Death05.xpm",
		"textures/heroAnimation/Dying/Death06.xpm",
		"textures/heroAnimation/Dying/Death07.xpm",
		"textures/heroAnimation/Dying/Death08.xpm",
		"textures/heroAnimation/Dying/Death09.xpm",
		"textures/heroAnimation/Dying/Death10.xpm",
		"textures/heroAnimation/Dying/Death11.xpm",
		"textures/heroAnimation/Dying/Death12.xpm",
		"textures/heroAnimation/Dying/Death13.xpm",
		"textures/heroAnimation/Dying/Death14.xpm"
	};

	int	i;

	// Load Idle Frames
	i = 0;
	while (i < 18)
	{
		pic->pic_hero_idle[i] = mlx_xpm_file_to_image(mlx_ptr, idle_paths[i],
				&pic->pic_width, &pic->pic_height);
		if (!pic->pic_hero_idle[i])
		{
			write(1, "Error! Cannot load hero idle frame.\n", 35);
			exit(1);
		}
		i++;
	}

	// Load Running Frames
	i = 0;
	while (i < 12)
	{
		pic->pic_hero_run[i] = mlx_xpm_file_to_image(mlx_ptr, run_paths[i],
				&pic->pic_width, &pic->pic_height);
		if (!pic->pic_hero_run[i])
		{
			write(1, "Error! Cannot load hero run frame.\n", 34);
			exit(1);
		}
		i++;
	}

	// Load Dying Frames
	i = 0;
	while (i < 15)
	{
		pic->pic_hero_death[i] = mlx_xpm_file_to_image(mlx_ptr, death_paths[i],
				&pic->pic_width, &pic->pic_height);
		if (!pic->pic_hero_death[i])
		{
			write(1, "Error! Cannot load hero death frame.\n", 36);
			exit(1);
		}
		i++;
	}

	pic->current_hero = 0;
	pic->hero_state = HERO_IDLE; // Default to Idle state
}
