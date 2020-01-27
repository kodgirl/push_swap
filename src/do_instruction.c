/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:31:59 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/27 20:07:44 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_swap **stack)
{
	t_swap	*head;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		*stack = (*stack)->next;
		head->next = (*stack)->next;
		(*stack)->next = head;
	}
}

void	ra(t_swap **stack)
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
}

int		pa(t_stack *stack)
{
	t_swap	*a_head;
	t_swap	*b_head;

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
		stack->a_stack->next = a_head;
		stack->b_stack = stack->b_stack->next;
	}
	stack->lena++;
	stack->lenb--;
	return (0);
}

int		pb(t_stack *stack)
{
	t_swap	*a_head;
	t_swap	*b_head;

	if (stack->lena == 0)
		return (0);
	a_head = stack->a_stack;
	b_head = stack->b_stack;
	if (stack->lena >= 1 && stack->lenb == 0)
	{
		stack->b_stack = a_head;
		stack->a_stack = stack->a_stack->next;
		stack->b_stack->next = NULL;
	}
	else if (stack->lena >= 1 && stack->lenb > 0)
	{
		stack->b_stack = a_head;
		stack->b_stack->next = b_head;
		stack->a_stack = stack->a_stack->next;
	}
	stack->lenb++;
	stack->lena--;
	return (0);
}

void	rra(t_swap **stack)
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
}
