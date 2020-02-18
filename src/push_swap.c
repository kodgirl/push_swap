/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:16:46 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/18 15:43:57 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_limits(t_swap **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a < b && a < c)
	{
		ra(stack, 1);
		if (c < b)
			sa(stack, 1);
	}
	if (b < a && b < c)
	{
		rra(stack, 1);
		if (a < c)
			sa(stack, 1);
	}
	if (c < a && c < b && b < a)
	{
		sa(stack, 1);
	}
}

void	find_limits(t_stack *stack)
{
	int max;
	int min;
	int mid;

	max = stack->lena - 1;
	min = 0;
	mid = max / 2;
	while (stack->lena > 3)
	{
		if (stack->a_stack->index == max ||\
		stack->a_stack->index == min || stack->a_stack->index == max - 1)
			ra(&stack->a_stack, 1);
		else if (stack->a_stack->index >= mid)
			pb(stack, 1);
		else if (stack->a_stack->index < mid)
		{
			pb(stack, 1);
			if (stack->lenb != 1)
				rb(&stack->b_stack, 1);
		}
	}
	sort_limits(&stack->a_stack);
}

void	finish_sort(t_stack *stack)
{
	t_swap	*tmp;
	int		last_index;

	tmp = stack->a_stack;
	while (tmp->next)
		tmp = tmp->next;
	last_index = tmp->index;
	while (stack->a_stack->index != 0)
	{
		if (stack->a_stack->index <= last_index / 2 + 1)
			rra(&stack->a_stack, 1);
		else
			ra(&stack->a_stack, 1);
	}
}

void	push_swap(t_stack *stack)
{
	if (stack->lena == 3)
		sort_of_three(&stack->a_stack);
	else if (!is_sorted(stack, 0) && stack->lena == 2)
		sa(&stack->a_stack, 1);
	else if (!is_sorted(stack, 0) && stack->lenb == 0)
		find_limits(stack);
	while (is_sorted(stack, 0) == 0)
	{
		if (stack->lenb != 0)
		{
			if (stack->lena == 3)
				pa(stack, 1);
			acts_to_zero(stack->b_stack);
			count_act1(stack);
			count_act2(stack);
			combine_instructions(stack->b_stack);
			if (stack->lenb != 0)
				find_minimal_act(stack);
		}
		if (stack->lenb == 0)
			finish_sort(stack);
	}
}
