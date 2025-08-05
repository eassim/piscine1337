# **************************************************************************** #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassim <eassim@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/02 21:41:21 by eassim            #+#    #+#              #
#    Updated: 2025/08/02 21:42:45 by eassim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc -Wall -Werror -Wextra -I./includes
OBJS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
NAME = libft.a

.PHONY: all clean fclean re

$(NAME):
	$(CC) -c srcs/ft_putchar.c -o srcs/ft_putchar.o
	$(CC) -c srcs/ft_swap.c -o srcs/ft_swap.o
	$(CC) -c srcs/ft_putstr.c -o srcs/ft_putstr.o
	$(CC) -c srcs/ft_strlen.c -o srcs/ft_strlen.o
	$(CC) -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o
	ar rcs $(NAME) $(OBJS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

all: $(NAME)
