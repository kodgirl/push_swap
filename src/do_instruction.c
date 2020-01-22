/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 12:31:59 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/22 14:59:51 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_swap **stack)
{
	t_swap	*head;

	if (*stack)
	{
		head = *stack;
		*stack = (*stack)->next;
		head->next = (*stack)->next;
		(*stack)->next = head;
	}
}

void	ra(t_swap **stack)
{
	t_swap	*head;

	if (*stack)
	{
		head = *stack;
		while ((*stack)->next)
			(*stack)= (*stack)->next;
		(*stack)->next = head;
		(*stack) = head->next;
		head->next = NULL;
	}
}

void	pa(t_swap **a_stack, t_swap **b_stack)
{
	t_swap	*a_head;
	t_swap	*b_head;
	
	if (*a_stack && !(*b_stack))
	{
		*b_stack = (t_swap *)ft_memalloc(sizeof(t_swap));
		(*b_stack)->num = a_head->num;
		(*a_stack) = (*a_stack)->next;
		(*b_stack)->next = NULL;
	}
	else if (*b_stack && *a_stack)
	{
		a_head = *a_stack;
		b_head = *b_stack;
		(*a_stack) = (*b_stack);
		(*b_stack)->next = a_head->next;
		(*b_stack) = b_head->next;
	}
	
}

void	rra(t_swap **stack)
{
	t_swap	*head;
	t_swap	*tmp;

	if (*stack)
	{
		head = *stack;
		while ((*stack)->next->next)
			(*stack) = (*stack)->next;
		tmp = (*stack);
		(*stack) = (*stack)->next;
		(*stack)->next = head;
		tmp->next = NULL;
	}
}
