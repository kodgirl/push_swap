/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:46:31 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/12 16:03:10 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack *stack, int flag)
{
	sa(&stack->a_stack, 0);
	sb(&stack->b_stack, 0);
	if (flag == 1)	
		printf("ss\n");
}

void	rr(t_stack *stack, int flag)
{
	ra(&stack->a_stack, 0);
	rb(&stack->b_stack, 0);
	if (flag == 1)
		printf("rr\n");
}

void	rrr(t_stack *stack, int flag)
{
	rra(&stack->a_stack, 0);
	rrb(&stack->b_stack, 0);
	if (flag == 1)
		printf("rrr\n");
}
