# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-ouad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/30 17:07:00 by nel-ouad          #+#    #+#              #
#    Updated: 2025/07/30 17:07:02 by nel-ouad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
RM := rm -f
CFLAGS := -Wall -Wextra -Werror
BIN := ft_display_file
SRC := ft_display_file.c

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:

fclean: clean
	$(RM) $(BIN)

.PHONY: all clean fclean