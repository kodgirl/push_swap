/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:38:51 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/04 16:08:11 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h> //delete
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "/Users/bjasper/Desktop/git/src/libft/libft.h"

# define ERROR_NOT_INT		"some arguments are not integers"
# define ERROR_BIGGER_INT	"some arguments are bigger than an integer"
# define ERROR_DUBL			"there are duplicates"
# define ERROR_BAD_INSTRUCT	"an instruction doesn’t exist"

typedef struct		s_swap
{
	int				num;
	struct s_swap	*next;
	int				index;
	int				act;	
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
	int				result;
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
int		read_instruct(char *line, t_stack *stack, t_instr *i_list);
int		f_atoi(const char *str, char **error);
void	make_instr(t_instr *i_list);
void	sa(t_swap **stack);
void	ra(t_swap **stack);
int		pa(t_stack *stack);
int		pb(t_stack *stack);
void	rra(t_swap **stack);
int		ft_make_stack(int ac, char **av, t_stack *stack);
void	f_lstadd(t_swap **stack, t_swap *new);
int		is_sorted(t_stack *stack);
int		is_dubl(t_swap *a_stack, char **error);
void	print_stacks(t_stack *stack);
void	push_swap(t_stack *stack);
void	find_index(t_swap *stack, int *tab, int len);
void 	ft_sort(int *tab, int len);
void	num_to_ind(t_swap *stack, int len);
void	print_index(t_stack *stack);
void	do_act(t_stack *stack);
void	sort_of_three(t_swap **stack);
void	finish_sort(t_stack *stack);

#endif