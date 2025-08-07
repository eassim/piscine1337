NAME = lib
CC = cc  -I/ft.h
OBJS = math.o str.o main.o

.PHONY: clean fclean $(NAME)

$(NAME): math.c str.c main.c
	$(CC) -c math.c -o math.o
	$(CC) -c str.c -o str.o
	$(CC) -c main.c -o main.o
	$(CC) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
