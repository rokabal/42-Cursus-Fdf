# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/19 11:48:19 by rkassouf          #+#    #+#              #
#    Updated: 2022/09/04 18:25:14 by rkassouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = rm -rf

# Executable / Libraries.

MLX				= libmlx_Linux.a
FT				= libft.a
NAME			= fdf

# Libraries.

LFT_DIR			= libft
MLX_DIR			= mlx_linux

# I/O Compilation.

SRCS_DIR		= src
OBJS_DIR		= obj

# Location of all header files used in the project.

INCS_DIR		:= inc
INCS_DIR		+= $(LFT_DIR)/includes
INCS_DIR		+= $(MLX_DIR)
INCS_DIR		+= /usr/include

# Every libraries needed to compile the project.

LFT				= $(LFT_DIR)/$(FT)
LMLX			= $(MLX_DIR)/$(MLX)

# Used header at each compilation to check file integrity.

INCS			= inc/fdf.h inc/keycode_linux.h

# Source files.
SRCS			= draw.c				free.c \
				  main.c				read_map.c \
				  rotation.c			hook.c \
				  color.c				colorset.c

# Some tricks in order to get the makefile doing his job.

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
C_OBJS			= $(addprefix $(D_OBJS), $(OBJS))
C_INCS			= $(foreach include, $(INCS_DIR), -I$(include))

# How files should be compiled.

CC				= gcc
OBJS			= $(SRCS:.c=.o)

# Compilation flags.

CFLAGS			= $(C_INCS) -Wall -Wextra -Werror

# For mac
# # Redefinition of the implicit compilation rule to prompt some informations.

# $(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
# 	@$(CC) $(CFLAGS) -c $< -o $@

# # Implicit make rule simply using dependancies to compile our project.

# all: $(OBJS_DIR) $(NAME)

# $(NAME): $(LMLX) $(LFT) $(C_OBJS)
#	$(CC) $(C_OBJS) -L$(LFT_DIR) -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# Redefinition of the implicit compilation rule to prompt some informations.

$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@$(CC) $(CFLAGS) -O3 -c $< -o $@

# Implicit make rule simply using dependancies to compile our project.

all: $(OBJS_DIR) $(NAME)

$(NAME): $(LMLX) $(LFT) $(C_OBJS)
	$(CC) $(C_OBJS) -L$(LFT_DIR) -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# Libraries installion using their own Makefile.

$(LFT):
	@make -sC $(LFT_DIR) -j

$(LMLX):
	@make -sC $(MLX_DIR) -j

# Rules used to create folders if they aren't already existing.

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Deleting all .o files.

clean :
	@make -sC $(LFT_DIR) clean
	@$(RM) -rf $(OBJS_DIR)

fclean : clean
	@make -sC $(LFT_DIR) fclean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
