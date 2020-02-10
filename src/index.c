/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:19:36 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/05 21:55:01 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/bjasper/Desktop/g/includes/push_swap.h"

void	find_index(t_swap *stack, int *tab, int len)
{
	int 	i;
	t_swap	*head;

	i = 0;
	head = stack;
	while (i < len)
	{
		while (stack->next != NULL)
		{
			if (stack->num == tab[i])
			{
				stack->index = i;
				break ;
			}
			stack = stack->next;
		}
		if (stack->num == tab[i])
			stack->index = i;
		++i;
		stack = head;
	}
}

void 	ft_sort(int *tab, int len)
{
	int i;
	int tmp;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			++i;		
	}
}

void	num_to_ind(t_swap *stack, int len)
{
	int	tab[len];
	int	i;
	t_swap	*head;

	head = stack;
	i = 0;
	while (i < len)
	{
		tab[i] = stack->num;
		if (stack->next != NULL)
			stack = stack->next;
		++i;
	}
	stack = head;
	ft_sort(tab, len);
	find_index(stack, tab, len);
}

void	print_index(t_stack *stack)
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
		printf("%d --- rb: %d --- rrb: %d --- ra: %d --- rrb: %d --- rr: %d --- rrr: %d\n", stack->a_stack->index, stack->a_stack->amount_rb, stack->a_stack->amount_rrb, stack->a_stack->amount_ra, stack->a_stack->amount_rra, stack->a_stack->amount_rr, stack->a_stack->amount_rrr);
		stack->a_stack = stack->a_stack->next;
		--a;
	}
	if (a == 1)
		printf("%d --- rb: %d --- rrb: %d --- ra: %d --- rrb: %d --- rr: %d --- rrr: %d\n", stack->a_stack->index, stack->a_stack->amount_rb, stack->a_stack->amount_rrb, stack->a_stack->amount_ra, stack->a_stack->amount_rra, stack->a_stack->amount_rr, stack->a_stack->amount_rrr);
	printf("\n\n");
	while (b > 1 && stack &&  stack->b_stack && stack->b_stack->next)
	{
		printf("%d --- rb: %d --- rrb: %d --- ra: %d --- rra: %d --- rr: %d --- rrr: %d\n", stack->b_stack->index, stack->b_stack->amount_rb, stack->b_stack->amount_rrb, stack->b_stack->amount_ra, stack->b_stack->amount_rra, stack->b_stack->amount_rr, stack->b_stack->amount_rrr);
		stack->b_stack = stack->b_stack->next;
		--b;
	}
	if (b == 1)
		printf("%d --- rb: %d --- rrb: %d --- ra: %d --- rra: %d --- rr: %d --- rrr: %d\n", stack->b_stack->index, stack->b_stack->amount_rb, stack->b_stack->amount_rrb, stack->b_stack->amount_ra, stack->b_stack->amount_rra, stack->b_stack->amount_rr, stack->b_stack->amount_rrr);
	stack->a_stack = a_head;
	stack->b_stack = b_head;
	printf("\n\n");
}
