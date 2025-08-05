CC = cc -Wall -Werror -Wextra -I./includes
OBJECTS = srcs/main.o srcs/calc.o srcs/operations.o
NAME = do-op

.PHONY = all clean fclean

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

srcs/main.o: srcs/main.c
	$(CC) -c srcs/main.c -o srcs/main.o

srcs/calc.o: srcs/calc.c
	$(CC) -c srcs/calc.c -o srcs/calc.o

srcs/operations.o: srcs/operations.c
	$(CC) -c srcs/operations.c -o srcs/operations.o

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
