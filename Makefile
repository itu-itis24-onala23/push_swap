NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c ft_split.c operations.c parsing.c sort.c stack.c utils.c big_number.c
all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean : 
	
fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re