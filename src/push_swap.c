/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:16:46 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/04 17:38:09 by bjasper          ###   ########.fr       */
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
		while (stack->a_stack->next && (stack->b_stack->index > stack->a_stack->index || stack->b_stack->index < a_tail->index))
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
		stack->b_stack->act = i;
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

void	sort_limits(t_swap **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (b > c && b > a)
	{
		if (c > a)
		{
			sa(stack);
			rra(stack);
		}
	}
	if (c > a && c > b)
	{
		if (a > b)
		{
			ra(stack);
			sa(stack);
		}
		else
			ra(stack);
	}
	if (a > b && a > c)
	{
		if (b < c)
			rra(stack);
		else
			sa(stack);
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
		if (stack->a_stack->index == max || stack->a_stack->index == min || stack->a_stack->index == max - 1)
		{
			ra(&stack->a_stack);
			stack->result++;
		}
		else if (stack->a_stack->index <= mid)
		{
			// if (stack->lena == 3 && stack->a_stack->index < stack->a_stack->next->index)
			// 	break ;
			// else
				pb(stack);
		}
		else if (stack->a_stack->index > mid)
		{
			pb(stack);
			ra(&stack->b_stack);
			stack->result++;
		}
		print_stacks(stack);
	}
	// if (stack->lena == 2 && stack->a_stack->index < stack->a_stack->next->index)
	// {
	// 	sa(&stack->a_stack);
	// 	stack->result++;
	// }
	sort_limits(&stack->a_stack);
}

void	finish_sort(t_stack *stack)
{
	while (stack->a_stack->index != 0)
	{
		ra(&stack->a_stack);
		stack->result++;
	}
}

void	push_swap(t_stack *stack)
{
	int i = 1;
	
	while (is_sorted(stack) == 0 && ( i > 0 || stack->lenb > 0))
	{
		if (stack->lenb == 0)
		{
			if (stack->lena == 3)
			{
				sort_of_three(&stack->a_stack);
			}
			else if (stack->lena > 3)
				find_limits(stack);
		}
		if (stack->lenb != 0)
		{
			if (stack->lena == 2)
			{
				pa(stack);
			}
			print_stacks(stack);
			count_act1(stack);
			count_act2(stack);
			// print_index(stack);
			do_act(stack);
			print_stacks(stack);
		}
		if (stack->lenb == 0)
			finish_sort(stack);
		print_stacks(stack);
		--i;
		// print_stacks(stack);
	}
	// print_stacks(stack);
}
