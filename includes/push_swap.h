/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:38:51 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/12 19:06:37 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../src/libft/libft.h"

# define ERROR_NOT_INT		"some arguments are not integers"
# define ERROR_BIGGER_INT	"some arguments are bigger than an integer"
# define ERROR_DUBL			"there are duplicates"
# define ERROR_BAD_INSTRUCT	"an instruction doesn’t exist"

typedef struct		s_swap
{
	int				num;
	struct s_swap	*next;
	int				index;
	int				amount_rb;
	int				amount_rrb;
	int				amount_ra;
	int				amount_rra;
	int				amount_rr;
	int				amount_rrr;
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

t_swap	*f_lstnew(int num);
int		read_instruct(char *line, t_stack *stack, t_instr *i_list);
int		f_atoi(const char *str, char **error);
void	make_instr(t_instr *i_list);
void	sa(t_swap **stack, int flag);
void	ra(t_swap **stack, int flag);
int		pa(t_stack *stack, int flag);
int		pb(t_stack *stack, int flag);
void	rra(t_swap **stack, int flag);
void	rrb(t_swap **stack, int flag);
void	rb(t_swap **stack, int flag);
void	sb(t_swap **stack, int flag);
void	ss(t_stack *stack, int flag);
void	rr(t_stack *stack, int flag);
void	rrr(t_stack *stack, int flag);
int		ft_make_stack(int ac, char **av, t_stack *stack);
void	f_lstadd(t_swap **stack, t_swap *new);
int		is_sorted(t_stack *stack, int flag);
int		is_dubl(t_swap *a_stack, char **error);
void	print_stacks(t_stack *stack);
void	push_swap(t_stack *stack);
void	find_index(t_swap *stack, int *tab, int len);
void	ft_sort(int *tab, int len);
void	num_to_ind(t_swap *stack, int len);
void	do_act(t_stack *stack, t_swap *min);
void	sort_of_three(t_swap **stack);
void	finish_sort(t_stack *stack);
void	combine_instructions(t_swap *b_stack);
t_swap	*find_minimal_act(t_stack *stack);
void	acts_to_zero(t_swap *stack);
void	del_stacks(t_stack *stack);
void	finish_sort(t_stack *stack);
void	count_act1(t_stack *stack);
void	count_act2(t_stack *stack);
int		insert_place(t_swap *iterator_a, t_swap *iterator_b, t_swap *a_past);

#endif
