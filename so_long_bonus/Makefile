# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 20:03:16 by yaboukir          #+#    #+#              #
#    Updated: 2025/01/02 23:18:05 by yaboukir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long_bonus

CC = cc

FLAGS = -Wall -Wextra -Werror -Imlx

SRC = so_long_bonus.c game_rend_bonus.c ft_keycodes_bonus.c ft_door_bonus.c \
      readingmap_bonus.c fetch_pic_bonus.c ft_printf_bonus.c ft_putchar_bonus.c \
      get_pic_bonus.c flood_fill_bonus.c ft_putnbr_bonus.c ft_split_bonus.c \
      get_next_line_bonus.c get_next_line_utils_bonus.c ft_length_bonus.c \
      moves_bonus.c parsing_bonus.c position_bonus.c rendering_bonus.c \
      wall_check_bonus.c ft_putstr_bonus.c get_enemy_pack.c ft_itoa_bonus.c ft_get_frames.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c so_long_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) so_long_bonus.h
	$(CC) $(OBJ) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
