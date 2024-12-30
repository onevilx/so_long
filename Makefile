# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 17:03:24 by yaboukir          #+#    #+#              #
#    Updated: 2024/12/29 18:00:16 by yaboukir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror -Imlx

SRC = so_long.c game_rend.c ft_buttons.c ft_door.c read_map.c fetch_pic.c \
	ft_printf.c ft_putchar.c get_pic.c flood_fill.c ft_putnbr.c ft_split.c \
	get_next_line.c get_next_line_utils.c ft_length.c moves.c parsing.c \
	position.c rendring.c wall_check.c ft_putstr.c

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
