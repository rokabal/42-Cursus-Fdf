# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 11:48:19 by rkassouf          #+#    #+#              #
#    Updated: 2022/08/21 20:16:20 by rkassouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= test

CC 		= gcc
FLAGS	=  -Wall -Werror -Wextra
RM		= /bin/rm -f

SRC		= src/main.c src/drawn.c src/get_next_line.c src/get_next_line_utils.c \
			src/read_map.c src/ft_split.c
OBJ		= $(SRC:.c=.o)

all:	$(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	make -C mlx
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
	@make clean -C mlx
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
	@rm -f libmlx.a

re : fclean all

.PHONY : all clean fclean re
