# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 14:14:45 by bjasper           #+#    #+#              #
#    Updated: 2020/01/29 13:25:30 by bjasper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = checker

SRC_C =	src/checker.c\
		src/liba.c\
		src/parce_instructions.c\
		src/do_instruction.c\
		src/main_checker.c

INCL = includes/push_swap.h 

GCC_FLAGS = -Wall -Werror -Wextra

OBJ_C = $(SRC_C:.c=.o)


NAME_P = push_swap

SRC_P =	src/push_swap.c\
		src/checker.c\
		src/liba.c\
		# src/do_instruction.c

OBJ_P = $(SRC_P:.c=.o)

.PHONY: all clean fclean re

all: $(NAME_C) $(NAME_P)

$(NAME_C): $(OBJ_C)
	make -C src/libft
	gcc -o $(NAME_C) $(OBJ_C) -L./src/libft -lft

$(NAME_P): $(OBJ_P)
	make -C src/libft
	gcc -o $(NAME_P) $(OBJ_P) -L./src/libft -lft
	
%.o: %.c ${INCL}
	gcc -I $(INCL) $< -c -o $@
	
clean:
	rm -rf $(OBJ_C) $(OBJ_P)

fclean: clean
	rm -rf $(NAME_C) $(NAME_P)

re: fclean all
