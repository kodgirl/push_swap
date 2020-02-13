/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:59:34 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/13 16:31:38 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	del_stacks(t_stack *stack)
{
	t_swap	*tmp;

	while (stack && stack->a_stack && stack->a_stack->next)
	{
		tmp = stack->a_stack;
		stack->a_stack = stack->a_stack->next;
		free(tmp);
	}
	if (stack && stack->a_stack)
		free(stack->a_stack);
	while (stack && stack->b_stack && stack->b_stack->next)
	{
		tmp = stack->b_stack;
		stack->b_stack = stack->b_stack->next;
		free(tmp);
	}
	if (stack && stack->b_stack)
		free(stack->b_stack);
}

void	del_double_massive(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&(str[i]));
		++i;
	}
	free(str);
}
