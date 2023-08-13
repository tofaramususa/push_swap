NAME = push_swap


SRCS = $(wildcard src/*.c utils/*.c)

CC = cc -g

CFLAGS = -Wall -Werror -Wextra -Iincludes

OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo ......Compiling.......

$(NAME): $(SRCS) $(OBJ) includes/push_swap.h
		@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
		@echo .........Compiling Done..............

clean:  
		@rm -rf $(OBJ)
		@echo .........Deleting Object Files..........

fclean: clean
		@rm -f $(NAME)
		@echo ..........Deleting Output Files.........

re: fclean all

.PHONY: all clean fclean re
