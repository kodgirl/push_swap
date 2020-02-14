/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_act.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:05:52 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/14 16:32:53 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_act(t_stack *stack, t_swap *min)
{
	while (min->amount_rr--)
		rr(stack, 1);
	while (min->amount_rrr--)
		rrr(stack, 1);
	while (min->amount_ra--)
		ra(&stack->a_stack, 1);
	while (min->amount_rb--)
		rb(&stack->b_stack, 1);
	while (min->amount_rra--)
		rra(&stack->a_stack, 1);
	while (min->amount_rrb--)
		rrb(&stack->b_stack, 1);
	pa(stack, 1);
}

void	find_minimal_act(t_stack *stack)
{
	int		act_current;
	int		act_min;
	t_swap	*min;
	t_swap	*tmp;

	min = stack->b_stack;
	tmp = stack->b_stack;
	act_min = min->amount_ra + min->amount_rb + min->amount_rrb +\
	min->amount_rra + min->amount_rr + min->amount_rrr;
	while (tmp->next)
	{
		tmp = tmp->next;
		act_current = tmp->amount_ra + tmp->amount_rb + tmp->amount_rrb +\
		tmp->amount_rra + tmp->amount_rr + tmp->amount_rrr;
		if (act_current < act_min)
		{
			min = tmp;
			act_min = act_current;
		}
	}
	do_act(stack, min);
}

void	sort_of_three(t_swap **stack)
{
	int a;
	int b;
	int c;

	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a < b && a < c && b > c)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (c < a && c < b)
	{
		if (a > b)
			sa(stack, 1);
		rra(stack, 1);
	}
	else if (b < a && b < c)
	{
		if (a > c)
			ra(stack, 1);
		else
			sa(stack, 1);
	}
}

void	acts_to_zero(t_swap *stack)
{
	while (stack)
	{
		stack->amount_rrr = 0;
		stack->amount_rrb = 0;
		stack->amount_rra = 0;
		stack->amount_rr = 0;
		stack->amount_rb = 0;
		stack->amount_ra = 0;
		stack = stack->next;
	}
}
