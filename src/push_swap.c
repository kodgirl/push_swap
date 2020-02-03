/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:16:46 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/03 17:33:15 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/bjasper/Desktop/git/includes/push_swap.h"

void	count_act2(t_stack *stack)
{
	t_swap	*a_head;
	t_swap	*a_tail;
	t_swap	*b_head;
	int		len;

	len = stack->lenb;
	b_head = stack->b_stack;
	a_head = stack->a_stack;
	while (stack->a_stack->next != NULL)
		stack->a_stack = stack->a_stack->next;
	a_tail = stack->a_stack;
	stack->a_stack = a_head;
	while (len > 0)
	{
		stack->a_stack = a_head;
		while (stack->b_stack->index > stack->a_stack->index || stack->b_stack->index < a_tail->index)
		{
			stack->b_stack->act++;
			a_tail = stack->a_stack;
			stack->a_stack = stack->a_stack->next;
		}
		if (stack->b_stack->next)
			stack->b_stack = stack->b_stack->next;
		--len;
	}
	stack->b_stack = b_head;
	stack->a_stack = a_head;
}

void	count_act1(t_stack *stack)
{
	int		i;
	int		mid;
	t_swap	*head;

	i = 0;
	head = stack->b_stack;
	mid = stack->lenb / 2;
	while (i <= mid && stack->b_stack->next)
	{
		printf("---------------------%d\n", i);
		stack->b_stack->act = i;
		// if (stack->b_stack->next)
			stack->b_stack = stack->b_stack->next;
		++i;
	}
	--i;
	if (stack->lenb % 2 == 0)
	{
		--i;
		while (i > 1)
		{
			stack->b_stack->act = i;
			--i;
			stack->b_stack = stack->b_stack->next;
		}
	}
	else if (stack->lenb % 2 != 0)
	{
		while (i > 1)
		{
			stack->b_stack->act = i;
			--i;
			stack->b_stack = stack->b_stack->next;
		}
	}
	if (stack->lenb == 1)
		stack->b_stack->act = 0;
	else
		stack->b_stack->act = 1;
	stack->b_stack = head;
}

void	find_limits(t_stack *stack)
{
	int max;
	int min;
	int mid;

	max = stack->lena - 1;
	min = 0;
	mid = max / 2;
	while (stack->lena > 2)
	{
		if (stack->a_stack->index == max || stack->a_stack->index == min)
			ra(&stack->a_stack);
		else if (stack->a_stack->index <= mid)
		{
			if (stack->lena == 3 && stack->a_stack->index < stack->a_stack->next->index)
				break ;
			else
				pb(stack);
		}
		else if (stack->a_stack->index > mid)
		{
			pb(stack);
			ra(&stack->b_stack);
		}
	}
	if (stack->lena == 2 && stack->a_stack->index < stack->a_stack->next->index)
		sa(&stack->a_stack);
}

void	finish_sort(t_swap **stack)
{
	while ((*stack)->index != 0)
		ra(stack);
}

void	push_swap(t_stack *stack)
{
	int i = 1;
	
	while (is_sorted(stack) == 0 && ( i > 0 || stack->lenb > 0))
	{
		if (stack->lenb == 0)
			find_limits(stack);
		if (stack->lena == 2)
			pa(stack);
		count_act1(stack);
		count_act2(stack);
		print_index(stack);
		do_act(stack);
		if (stack->lenb == 0)
			finish_sort(&stack->a_stack);
		--i;
	}
	print_stacks(stack);
}
