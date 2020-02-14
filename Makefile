# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 14:14:45 by bjasper           #+#    #+#              #
#    Updated: 2020/02/14 20:13:38 by bjasper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = checker

SRC_C =	src/checker.c\
		src/liba.c\
		src/parce_instructions.c\
		src/a_instructions.c\
		src/b_instructions.c\
		src/ab_instructions.c\
		src/main_checker.c\
		src/delete.c

INCL = includes/push_swap.h 

GCC_FLAGS = -Wall -Werror -Wextra

OBJ_C = $(SRC_C:.c=.o)


NAME_P = push_swap

SRC_P =	src/main_pushswap.c\
		src/push_swap.c\
		src/checker.c\
		src/liba.c\
		src/index.c\
		src/a_instructions.c\
		src/b_instructions.c\
		src/ab_instructions.c\
		src/do_act.c\
		src/act_count.c\
		src/delete.c

OBJ_P = $(SRC_P:.c=.o)

.PHONY: all clean fclean re

all: $(NAME_C) $(NAME_P)

$(NAME_C): $(OBJ_C)
	make -C src/libft
	gcc -o $(NAME_C) $(OBJ_C) -L./src/libft -lft

$(NAME_P): $(OBJ_P)
	make -C src/libft
	gcc -g -o $(NAME_P) $(OBJ_P) -L./src/libft -lft
	
%.o: %.c ${INCL}
	gcc -g -I $(INCL) $< -c -o $@
	
clean:
	rm -rf $(OBJ_C) $(OBJ_P)
	make clean -C src/libft/

fclean: clean
	rm -rf $(NAME_C) $(NAME_P)

re: fclean all
