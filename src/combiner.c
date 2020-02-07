/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combiner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 21:42:41 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/05 21:50:06 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
