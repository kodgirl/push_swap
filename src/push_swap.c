/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:16:46 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/29 21:57:29 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/bjasper/Desktop/git/includes/push_swap.h"

void	count_act(t_stack *stack)
{
	int i;
	int mid;
	t_swap *head;

	i = 0;
	head = stack->b_stack;
	mid = stack->lenb / 2;
	while (i <= mid)
	{
		stack->b_stack->act = i;
		++i;
		stack->b_stack = stack->b_stack->next;
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
	stack->b_stack->act = i;
	stack->b_stack = head;
}

void	print_acts(t_stack *stack)
{
	t_swap *a_head;
	t_swap *b_head;
	int		a;
	int		b;
	
	a_head = stack->a_stack;
	b_head = stack->b_stack;
	a = stack->lena;
	b = stack->lenb;
	printf("lena: %d\n", a);
	printf("lenb: %d\n", b);
	while (a > 1)
	{
		printf("%d\n", stack->a_stack->act);
		stack->a_stack = stack->a_stack->next;
		--a;
	}
	if (a == 1)
		printf("%d\n", stack->a_stack->act);
	printf("\n\n");
	while (b > 1)
	{
		printf("%d\n", stack->b_stack->act);
		stack->b_stack = stack->b_stack->next;
		--b;
	}
	if (b == 1)
		printf("%d\n", stack->b_stack->act);
	stack->a_stack = a_head;
	stack->b_stack = b_head;
}

void 	find_limits(t_stack *stack)
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
			pb(stack);
		else if (stack->a_stack->index > mid)
		{
			pb(stack);
			ra(&stack->b_stack);
		}
	}
	if (stack->a_stack->num < stack->a_stack->next->num)
		sa(&stack->a_stack);
}

void	push_swap(t_stack *stack)
{
	if(is_sorted(stack) == 0)
	{
		find_limits(stack);
		count_act(stack);
		print_acts(stack);
	}	
}
