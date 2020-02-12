/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:22:37 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/12 16:04:44 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_instr(t_instr *i_list)
{
	i_list->in[0] = "sa";
	i_list->in[1] = "sb";
	i_list->in[2] = "ss";
	i_list->in[3] = "ra";
	i_list->in[4] = "rb";
	i_list->in[5] = "rr";
	i_list->in[6] = "pa";
	i_list->in[7] = "pb";
	i_list->in[8] = "rra";
	i_list->in[9] = "rrb";
	i_list->in[10] = "rrr";
}

int		change_stacks(t_stack *stack, int i)
{
	if (i == 0)
		sa(&stack->a_stack, 0);
	if (i == 1)
		sb(&stack->b_stack, 0);
	if (i == 2)
		ss(stack, 0);
	if (i == 3)
		ra(&stack->a_stack, 0);
	if (i == 4)
		rb(&stack->b_stack, 0);
	if (i == 5)
		rr(stack, 0);
	if (i == 6)
		pa(stack, 0);
	if (i == 7)
		pb(stack, 0);
	if (i == 8)
		rra(&stack->a_stack, 0);
	if (i == 9)
		rrb(&stack->b_stack, 0);
	if (i == 10)
		rrr(stack, 0);
	return (1);
}

int		is_valid_instr(char *line, t_instr *i_list)
{
	i_list->i = 0;
	if (ft_strlen(line) != 3 && ft_strlen(line) != 2)
		return (0);
	while (i_list->i <= 10)
	{
		if (ft_strcmp(line, i_list->in[i_list->i]) == 0)
			return (1);
		i_list->i++;
	}
	return (0);
}

int		read_instruct(char *line, t_stack *stack, t_instr *i_list)
{
	if (is_valid_instr(line, i_list) == 0)
	{
		printf("%s", ERROR_BAD_INSTRUCT);
		return (0);
	}
	change_stacks(stack, i_list->i);
	return (1);
}
