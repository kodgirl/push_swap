/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:16:46 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/05 21:44:43 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/bjasper/Desktop/g/includes/push_swap.h"
int		insert_place(t_swap *iterator_a, t_swap *iterator_b, t_swap *a_past)
{
	int			index_a;
	
	index_a = 0;
	while (iterator_a && (iterator_b->index > iterator_a->index || iterator_b->index < a_past->index))
	{
		index_a++;
		a_past = iterator_a;
		iterator_a = iterator_a->next;
	}	
	return (index_a);
}

void	count_act2(t_stack *stack)
{
	t_swap		*iterator_b;
	t_swap		*a_past;
	t_swap		*tail;
	int			mid;
	int			place;
	
	mid = stack->lena / 2;
	iterator_b = stack->b_stack;
	tail = stack->a_stack;
	while (tail->next != NULL)
		tail = tail->next;	
	while (iterator_b)
	{
		a_past = tail;
		place = insert_place(stack->a_stack, iterator_b, a_past);
		if (place <= mid)
			iterator_b->amount_ra = place;
		else
			iterator_b->amount_rra = stack->lena - place;
		iterator_b = iterator_b->next;
	}
}

void	count_act1(t_stack *stack)
{
	int		i;
	int		mid;
	t_swap	*head;

	i = 0;
	head = stack->b_stack;
	mid = stack->lenb / 2;
	while (i < stack->lenb)
	{
		if (i <= mid)
			stack->b_stack->amount_rb = i;
		else
			stack->b_stack->amount_rrb = stack->lenb - i;
		stack->b_stack = stack->b_stack->next;
		++i;
	}
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
		else if (stack->a_stack->index >= mid)
			pb(stack);
		else if (stack->a_stack->index < mid)
		{
			pb(stack);
			ra(&stack->b_stack);
			stack->result++;
		}
	}
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
	
	if (stack->lena == 3)
		sort_of_three(&stack->a_stack);
	else if (!is_sorted(stack) && stack->lenb == 0)
		find_limits(stack);
	print_stacks(stack);
	if (is_sorted(stack) == 0)
	{
		if (stack->lenb != 0)
		{
			if (stack->lena == 3)
				pa(stack);
			count_act1(stack);
			count_act2(stack);
			combine_instructions(stack->b_stack);
			print_stacks(stack);
			print_index(stack);
		// 	// print_index(stack);
		// 	do_act(stack);
		// 	print_stacks(stack);
		// }
		// if (stack->lenb == 0)
		// 	finish_sort(stack);
		// print_stacks(stack);
		// --i;
		// print_stacks(stack);
		}
	}
	print_stacks(stack);
}
