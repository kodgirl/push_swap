/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:59:34 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/13 15:31:04 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	del_stacks(t_stack **stack)
{
	t_swap	*tmp;

	while (stack && *stack != NULL && (*stack)->a_stack != NULL)
	{
		if ((*stack)->a_stack->next != NULL)
		{
			tmp = (*stack)->a_stack->next;
		}
		free((*stack)->a_stack);
		(*stack)->a_stack = tmp;
	}
	while (stack != NULL && (*stack)->b_stack != NULL)
	{
		if ((*stack)->b_stack->next != NULL)
		{
			tmp = (*stack)->b_stack->next;
		}
		free((*stack)->b_stack);
		(*stack)->a_stack = tmp;
	}
	if (*stack != NULL)
		free(*stack);
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
