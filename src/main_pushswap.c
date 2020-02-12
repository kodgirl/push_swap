/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:15:10 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/12 19:33:21 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	t_stack	*stack;
	char	*line;
	t_instr	i_list;
	t_stack	*head;

	if (ac == 1)
		return (0);
	stack = ft_memalloc(sizeof(t_stack));
	if (ft_make_stack(ac - 1, av, stack) == 0)
	{
		del_stacks(stack);
		return (0);
	}
	num_to_ind(stack->a_stack, stack->lena);
	push_swap(stack);
	del_stacks(stack);
	return (0);
}
