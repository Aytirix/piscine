# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 10:44:35 by thmouty           #+#    #+#              #
#    Updated: 2024/03/07 10:47:00 by thmouty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
DIR_SRC = ./srcs/
HEAD = ./includes/
SRC = $(DIR_SRC)ft_putchar.c $(DIR_SRC)ft_putstr.c $(DIR_SRC)ft_strcmp.c $(DIR_SRC)ft_strlen.c $(DIR_SRC)ft_swap.c
OBJ = $(SRC:.c=.o)
RM = rm -f
all : $(NAME)
$(NAME): $(OBJ)
    ar rcs $(NAME) $(OBJ)
%.o: %.c
    $(CC) $(CFLAGS)  -c $*.c -I$(HEAD) -o $*.o
    
clean: 
    $(RM) $(OBJ)
fclean: clean
    $(RM) $(NAME)
re: fclean all
    
.PHONY: all clean fclean re