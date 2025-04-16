NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

INC_DIR = ./include/
I = -I $(INC_DIR)

SRCS = main.c ./srcs/init.c ./srcs/errors.c ./srcs/print.c ./srcs/routine.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(I) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(I) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
