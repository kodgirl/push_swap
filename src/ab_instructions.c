/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:46:31 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/14 16:25:04 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack *stack, int flag)
{
	sa(&stack->a_stack, 0);
	sb(&stack->b_stack, 0);
	if (flag == 1)
		write(1, "ss\n", 3);
}

void	rr(t_stack *stack, int flag)
{
	ra(&stack->a_stack, 0);
	rb(&stack->b_stack, 0);
	if (flag == 1)
		write(1, "rr\n", 3);
}

void	rrr(t_stack *stack, int flag)
{
	rra(&stack->a_stack, 0);
	rrb(&stack->b_stack, 0);
	if (flag == 1)
		write(1, "rrr\n", 4);
}
