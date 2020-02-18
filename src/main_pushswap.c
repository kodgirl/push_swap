/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:15:10 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/18 14:41:54 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	t_stack	stack;

	ft_bzero(&stack, sizeof(t_stack));
	if (ac == 1)
		return (0);
	if (ft_make_stack(ac - 1, av, &stack) == 0)
		return (0);
	if (stack.lena != 0)
	{
		num_to_ind((&stack)->a_stack, (&stack)->lena);
		push_swap(&stack);
	}
	del_stacks(&stack);
	return (0);
}
