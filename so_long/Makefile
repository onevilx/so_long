# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 20:03:16 by yaboukir          #+#    #+#              #
#    Updated: 2024/12/31 19:04:34 by yaboukir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror -Imlx

SRC = so_long.c game_rend.c ft_keycodes.c ft_door.c readingmap.c fetch_pic.c \
	ft_printf.c ft_putchar.c get_pic.c flood_fill.c ft_putnbr.c ft_split.c \
	get_next_line.c get_next_line_utils.c ft_length.c moves.c parsing.c \
	position.c rendering.c wall_check.c ft_putstr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) so_long.h
	$(CC) $(OBJ) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
