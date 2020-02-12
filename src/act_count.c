/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:42:41 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/12 18:05:26 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	combine_instructions(t_swap *b_stack)
{
	while (b_stack)
	{
		while (b_stack->amount_ra != 0 && b_stack->amount_rb != 0)
		{
			b_stack->amount_ra--;
			b_stack->amount_rb--;
			b_stack->amount_rr++;
		}
		while (b_stack->amount_rra != 0 && b_stack->amount_rrb != 0)
		{
			b_stack->amount_rra--;
			b_stack->amount_rrb--;
			b_stack->amount_rrr++;
		}
		b_stack = b_stack->next;
	}
}
