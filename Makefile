NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -g

SRC = checks.c ft_utils.c init.c print.c threading.c actions.c \
      destroy.c get_time.c main.c valid.c
OBJ = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
