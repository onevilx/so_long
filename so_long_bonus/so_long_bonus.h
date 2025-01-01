/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:48:25 by yaboukir          #+#    #+#             */
/*   Updated: 2024/12/31 20:31:07 by yaboukir         ###   ########.fr       */
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
#  define BUFFER_SIZE 10
# endif

typedef struct p_position
{
	int	row;
	int	column;
}		t_posi;

typedef struct s_infob
{
    int     move;                // Number of moves or steps
    int     pic_width;           // Width of a single image
    int     pic_height;          // Height of a single image
    char    **rows;              // Game map rows
    void    *pic_closeddoor;     // Image for a closed door
    void    *pic_opendoor;       // Image for an open door
    void    *pic_wall;           // Image for walls
    void    *pic_background;     // Image for the background
    void    *pic_character;      // Image for the main character
    void    *mlx_ptr;            // Pointer to MLX instance
    void    *mlx_window;         // Pointer to the MLX window
    void    *pic_coin_frames[10]; // Array for coin animation frames (adjust size as needed)
    int     num_coin_frames;     // Number of animation frames for the coin
    int     current_coin_frame;  // Index of the current frame for the coin
    int     frame_counter;    // Counter to track time for frame switching
    int     frame_delay;      // Number of frames to wait before switching
}   t_infob;


char	*get_next_line(int fd);
int		ft_strchr(const char *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	first_row(char **rows);
void	each_row(char **rows);
void	last_row(char **rows);
void	map_parsing(char **lines, char *maps);
char	**filling(char **lines, int x, int y);
char	*readingmap(char *row);
void	map_check(char **lines);
void	name_error(char *name);
void	ft_rendering(char *maps);
void	get_texture_background(t_infob *pic, void *mlx_ptr);
void	get_texture_closeddoor(t_infob *pic, void *mlx_ptr);
void	get_texture_character(t_infob *pic, void *mlx_ptr);
void	get_texture_opendoor(t_infob *pic, void *mlx_ptr);
void	get_texture_coin(t_infob *pic, void *mlx_ptr);
void	get_texture_wall(t_infob *pic, void *mlx_ptr);
t_infob	fetch_pic(t_infob *img, void *mlx_ptr);
int		ft_keycodes(int button, void *p);
void	up(t_infob *pic);
void	left(t_infob *pic);
void	down(t_infob *pic);
void	right(t_infob *pic);
size_t	check_len_rowsmap(char **lines);
size_t	check_col_lenmap(char *lines);
void	rendersize_background(char **rows, t_infob *pic);
void	rendersize_character(char **rows, t_infob *pic);
void	rendersize_wall(char **rows, t_infob *pic);
void	rendersize_coin(char **rows, t_infob *pic);
void	rendersize_door(char **rows, t_infob *pic);
void	ft_door(char **rows, t_infob *pic);
int		door_checker(char **rows);
int		check_coins(char **rows);
void	checking_the_line(char **lines);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_printf(const char *f, ...);
int		ft_putchar(char c);
void	ren_again(t_infob *pic, t_posi coor, char **rows);
void	free_function(char **rows);
t_posi	ft_position(char **rows, int k);

#endif
