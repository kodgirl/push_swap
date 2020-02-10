/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:46:38 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/10 19:27:40 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sb(t_swap **stack, int flag)
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
		printf("sb\n");
}

void	rb(t_swap **stack, int flag)
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
		printf("rb\n");
}

int		pb(t_stack *stack, int flag)
{
	t_swap	*a_head;
	t_swap	*b_head;

	if (flag == 1)
		printf("pb\n");
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
		stack->a_stack = stack->a_stack->next;
		stack->b_stack->next = b_head;
	}
	stack->lenb++;
	stack->lena--;
	return (0);
}

void	rrb(t_swap **stack, int flag)
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
		printf("rrb\n");
}
