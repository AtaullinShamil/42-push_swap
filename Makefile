# **************************************************************************** #
#                                                                              #
#    Makefile                                                                  #
#                                                                              #
#    By: Ataullin Shamil                                                       #
#                                                                              #
#    Created: 2022/02/18                                                       #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
FLAGS = -Wall -Werror -Wextra
HEADER = push_swap.h
RM = rm -rf

LIST =		error.c \
			ft_split.c \
			libft.c \
			parser.c \
			parser_array.c \
			parser_array_helper.c \
			push_swap.c \
			rules_1.c \
			rules_2.c \
			sort.c \
			sort_helper.c \
			sort_score.c \
			sort_mean.c \
			minisort.c

OBJ = $(LIST:.c=.o)

all: $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
