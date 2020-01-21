/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 13:22:37 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/21 14:56:01 by bjasper          ###   ########.fr       */
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

// change_stacks(t_swap **a_stack, t_swap **b_stack, char *line)
// {
	
// }

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

int		read_instruct(char *line, t_swap **a_stack,	t_swap **b_stack, t_instr *i_list)
{
	if (is_valid_instr(line, i_list) == 0)
	{
		printf("%s", ERROR_BAD_INSTRUCT);
		return (0);
	}
	// change_stacks(a_stack, b_stack, line);
	return (1);
}

