NAME = philo

CC = cc -pthread
CFLAGS = -Wall -Wextra -Werror -g3

INC_DIR = ./include/
I = -I $(INC_DIR)

SRC_DIR = ./srcs
OBJ_DIR = ./obj

SRCS = main.c $(SRC_DIR)/init.c $(SRC_DIR)/errors.c $(SRC_DIR)/print.c \
		$(SRC_DIR)/routine.c $(SRC_DIR)/utils.c $(SRC_DIR)/time.c \
		$(SRC_DIR)/eat.c $(SRC_DIR)/monitoring.c $(SRC_DIR)/utils2.c $(SRC_DIR)/threads.c
OBJS = $(SRCS:.c=.o)
OBJ_FILES = $(patsubst %.o,$(OBJ_DIR)/%.o,$(notdir $(OBJS)))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(I) $^ -o $@

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(I) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(I) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
