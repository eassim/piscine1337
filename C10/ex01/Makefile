# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-ouad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 17:53:51 by nel-ouad          #+#    #+#              #
#    Updated: 2025/08/04 17:53:54 by nel-ouad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
RM := rm -f
CFLAGS := -Wall -Wextra -Werror
BIN := ft_cat
SRC := ft_cat.c

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:

fclean: clean
	$(RM) $(BIN)

.PHONY: all clean fclean
