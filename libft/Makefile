# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/28 12:48:30 by rkassouf          #+#    #+#              #
#    Updated: 2022/08/26 21:25:51 by rkassouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable's name (Can be changed)

NAME		= libft.a

# All the directories needed to know where files should be (Can be changed)

SRCDIR 		= src/
OBJDIR 		= obj/
INCDIR 		= includes/
INCS   		= libft.h

# Source files (Can be changed)

SRC			= ft_memset.c 					ft_bzero.c \
			  ft_memcpy.c 					ft_memcmp.c \
			  ft_memchr.c 					ft_memmove.c \
			  ft_calloc.c					ft_isprint.c \
			  ft_isalpha.c 					ft_isdigit.c \
			  ft_isalnum.c 					ft_isascii.c \
			  ft_toupper.c 					ft_tolower.c \
			  ft_strchr.c 					ft_strrchr.c \
			  ft_strlen.c 					ft_strdup.c \
			  ft_strlcpy.c 					ft_strlcat.c \
			  ft_strnstr.c 					ft_strncmp.c \
			  ft_putchar_fd.c 				ft_putstr_fd.c \
			  ft_putendl_fd.c 				ft_putnbr_fd.c \
			  ft_substr.c 					ft_strjoin.c \
			  ft_strtrim.c 					ft_split.c \
			  ft_itoa.c						ft_atoi.c \
			  ft_strmapi.c 					ft_striteri.c \
			  ft_lstnew.c 					ft_lstadd_front.c \
			  ft_lstsize.c 					ft_lstlast.c \
			  ft_lstadd_back.c 				ft_lstdelone.c \
			  ft_lstclear.c 				ft_lstiter.c \
			  ft_lstmap.c					ft_exit_on_err.c \
			  get_next_line.c

# Some tricks in order to get the makefile doing his job the way I want (Can't be changed)

CSRC		= $(addprefix $(SRCDIR), $(SRC))
COBJ		= $(addprefix $(OBJDIR), $(OBJ))
HEADERS		= $(foreach header, $(INCS), $(INCDIR)$(header))
INCLUDES	= $(foreach include, $(INCDIR), -I./$(include))

# How files should be compiled with set flags (Can be changed)

CC 			= gcc
OBJ			= $(SRC:.c=.o)
CFLAGS		= $(INCLUDES) -Wall -Wextra -Werror

# Rule called upon 'make'

all: $(NAME)

# Build the library when all .c files are compiled into .o files and then indexing it

$(NAME): $(OBJDIR) $(COBJ)
	@ar rcs $(NAME) $(COBJ)

# Tries to create objs directory

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Redefinition of implicit compilation rule to prompt file names during the said compilation

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

# Deleting all .o files and then the directory where they were located

clean:
	@$(RM) -rf $(OBJDIR)

# Deleting the library after cleaning up all .o files

fclean: clean
	@$(RM) $(NAME)

# Delete all .o files then the library and rebuild the whole thing again

re: fclean all

.PHONY: all clean fclean re
