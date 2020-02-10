/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:46:31 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/10 19:37:52 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack *stack, int flag)
{
	sa(&stack->a_stack, flag);
	sb(&stack->b_stack, flag);
	if (flag == 1)	
		printf("ss\n");
}

void	rr(t_stack *stack, int flag)
{
	ra(&stack->a_stack, flag);
	rb(&stack->b_stack, flag);
	if (flag == 1)
		printf("rr\n");
}

void	rrr(t_stack *stack, int flag)
{
	rra(&stack->a_stack, flag);
	rrb(&stack->b_stack, flag);
	if (flag == 1)
		printf("rrr\n");
}
