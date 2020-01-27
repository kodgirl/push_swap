# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 14:14:45 by bjasper           #+#    #+#              #
#    Updated: 2020/01/27 18:10:45 by bjasper          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	src/checker.c\
		src/liba.c\
		src/parce_instructions.c\
		src/do_instruction.c

INCL = includes/push_swap.h 

GCC_FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME) clean		//remove clean

$(NAME): $(OBJ)
	make -C src/libft
	gcc -o $(NAME) $(OBJ) -L./src/libft -lft
	
%.o: %.c ${INCL}
	gcc -I $(INCL) $< -c -o $@
	
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
