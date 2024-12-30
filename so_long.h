/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:50:50 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/29 17:06:28 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif
#define HERO_IDLE 0
#define HERO_RUNNING 1
#define HERO_DEATH 2

#define ENEMY_IDLE 0
#define ENEMY_WALKING 1
#define ENEMY_RUNNING 2

typedef struct p_position
{
	int	row;
	int	column;
}		t_position;

typedef struct info_struct
{
	char	**rows;
	int		pic_width;
	int		pic_height;
	int		movesh;

	void	*pic_closeddoor;
	void	*pic_opendoor;
	void	*pic_wall;
	void	*pic_background;

	void	*pic_coin[9];
	int		current_coin;

	void	*pic_hero_idle[18];
	void	*pic_hero_run[12];
	void	*pic_hero_death[15];
	int		current_hero;
	int		hero_state;

	void	*pic_enemy_idle[18];
	void	*pic_enemy_walk[24];
	void	*pic_enemy_run[12];
	int		current_enemy;
	int		enemy_state;

	void	*mlx_ptr;
	void	*mlx_window;
}		t_info;

int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		door_checker(char **rows);
int		redeem_coins(char **rows);
int		ft_buttons(int button, void *p);
int		ft_printf(const char *str, ...);
int		ft_strchr(const char *str, char c);
int		ft_strchr(const char *str, char c);
char	*read_map(char *row);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	**filling(char **rows, int x, int y);
char	*ft_strjoin(char *s1, char const *s2);
void	up(t_info *pic);
void	down(t_info *pic);
void	left(t_info *pic);
void	render(char *map);
void	right(t_info *pic);
void	each_row(char **rows);
void	last_row(char **rows);
void	name_error(char *name);
void	first_row(char **rows);
void	map_check(char **rows);
void	free_function(char **rows);
void	checking_the_line(char **rows);
void	ft_door(char **rows, t_info *pic);
void	map_parsing(char **rows, char *maps);
void	get_wall(t_info *pic, void *mlx_ptr);
void	render_wall(char **rows, t_info *pic);
void	render_hero(char **rows, t_info *pic);
void	render_coin(char **rows, t_info *pic);
void	render_door(char **rows, t_info *pic);
void	render_enemy(char **rows, t_info *pic);
void	render_background(char **rows, t_info *pic);
void	get_opendoor(t_info *pic, void *mlx_ptr);
void	get_closeddoor(t_info *pic, void *mlx_ptr);
void	get_background(t_info *pic, void *mlx_ptr);
void	load_coin_animation(t_info *pic, void *mlx_ptr);
void	load_hero_animation(t_info *pic, void *mlx_ptr);
void	load_enemy_animation(t_info *pic, void *mlx_ptr);
void	ren_again(t_info *pic, t_position coor, char **rows);
void	open_window(t_info *pic, void *mlx_ptr, char **rows);
void	handle_door(t_info *pic, char **rows, size_t m, size_t n);
size_t	check_col_len(char *rows);
size_t	ft_strlen(const char *str);
size_t	check_len_rows(char **rows);
t_info	fetch_pic(t_info *pic, void *mlx_ptr);
t_position	ft_position(char **rows, int k);

#endif
