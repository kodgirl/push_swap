/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:31:59 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/13 17:27:00 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_swap **stack, int flag)
{
	t_swap	*head;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		*stack = (*stack)->next;
		head->next = (*stack)->next;
		(*stack)->next = head;
	}
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	ra(t_swap **stack, int flag)
{
	t_swap	*head;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->next = head;
		(*stack) = head->next;
		head->next = NULL;
	}
	if (flag == 1)
		write(1, "ra\n", 3);
}

int		pa(t_stack *stack, int flag)
{
	t_swap	*a_head;
	t_swap	*b_head;

	if (flag == 1)
		write(1, "pa\n", 3);
	if (stack->lenb == 0)
		return (0);
	a_head = stack->a_stack;
	b_head = stack->b_stack;
	if (stack->lenb >= 1 && stack->lena == 0)
	{
		stack->a_stack = b_head;
		stack->b_stack = stack->b_stack->next;
		stack->a_stack->next = NULL;
	}
	else if (stack->lenb >= 1 && stack->lena > 0)
	{
		stack->a_stack = b_head;
		stack->b_stack = stack->b_stack->next;
		stack->a_stack->next = a_head;
	}
	stack->lena++;
	stack->lenb--;
	return (0);
}

void	rra(t_swap **stack, int flag)
{
	t_swap	*head;
	t_swap	*tmp;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		while ((*stack)->next->next)
			(*stack) = (*stack)->next;
		tmp = (*stack);
		(*stack) = (*stack)->next;
		(*stack)->next = head;
		tmp->next = NULL;
	}
	if (flag == 1)
		write(1, "rra\n", 4);
}
