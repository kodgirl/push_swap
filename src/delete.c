/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:13:20 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/12 19:34:07 by bjasper          ###   ########.fr       */
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
	if (stack)
		free(stack);
}
