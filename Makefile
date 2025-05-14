CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRC = main.c utiles.c
NAME = philo
OBJ = $(SRC:.c=.o)
all : $(NAME)
$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME) 

re: fclean all
