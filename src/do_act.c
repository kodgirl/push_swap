/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:05:52 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/05 19:59:54 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/bjasper/Desktop/g/includes/push_swap.h"

void	do_act(t_stack *stack)
{
	int a;
	int b;
	int c;
	int i;
	t_swap	*b_head;

	a = 10;
	b = 10;
	c = 10;
	b_head = stack->b_stack;
	// a = stack->b_stack->act;
	if (stack->lenb > 1)
		// b = stack->b_stack->next->act;
	while (stack->b_stack->next)
		stack->b_stack = stack->b_stack->next;
	c = stack->b_stack->index;
	stack->b_stack = b_head;
	if (a <= b && a <= c)
	{
		while (a > 0)
		{
			ra(&stack->a_stack);
			stack->result++;
			--a;
		}
		pa(stack);
	
	}
	else if (b <= a && b <= c)
	{
		sa(&stack->b_stack);
		stack->result++;
		while (a > 1)
		{
			ra(&stack->a_stack);
			stack->result++;
			--a;
		}
		pa(stack);
	}
	else if (c <= a && c <= b)
	{
		rra(&stack->b_stack);
		stack->result++;
		while (a > 1)
		{
			ra(&stack->a_stack);
			--a;
			stack->result++;
		}
		pa(stack);
	}
}

void	sort_of_three(t_swap **stack)
{
	int a;
	int b;
	int c;

	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a < b && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (c < a && c < b)
	{
		if (a < b)
			rra(stack);
	}
	else if (b < a && b < c)
	{
		if (a > c)
			ra(stack);
		else
			sa(stack);
	}
}