NAME = do-op

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): main.c operations.c
	cc -w -w -w -I/ft.h -c main.c -o main.o
	cc -w -w -w -I/ft.h -c operations.c -o operations.o
	cc main.o operations.o -o do-op

clean:
	rm *.o

fclean: clean
	rm do-op

re: fclean
	make
