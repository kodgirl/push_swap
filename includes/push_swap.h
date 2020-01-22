/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:38:51 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/22 15:05:33 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h> //delete
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "/Users/bjasper/Desktop/push_swap/src/libft/libft.h"

# define ERROR_NOT_INT		"some arguments are not integers"
# define ERROR_BIGGER_INT	"some arguments are bigger than an integer"
# define ERROR_DUBL			"there are duplicates"
# define ERROR_BAD_INSTRUCT	"an instruction doesn’t exist"

typedef struct		s_swap
{
	int				num;
	struct s_swap	*next;	
}					t_swap;

typedef struct		s_instr
{
	char			*in[11];
	int				i;			
}					t_instr;

typedef struct		s_stack
{
	t_swap			*a_stack;
	t_swap			*b_stack;
	int				lena;
	int				lenb;
}					t_stack;


//# define SA 0	
/*
typedef enum		e_qwe
{
	SA,
	SB,
	SS,	
}					t_qwe;
*/


t_swap	*f_lstnew(int num);
int		read_instruct(char *line, t_swap **a_stack,	t_swap	**b_stack, t_instr *i_list);
int		f_atoi(const char *str, char **error);
void	make_instr(t_instr *i_list);
void	sa(t_swap **stack);
void	ra(t_swap **stack);
void	pa(t_swap **a_stack, t_swap **b_stack);
void	rra(t_swap **stack);
int		ft_make_stack(int ac, char **av, t_swap **a_stack);

#endif