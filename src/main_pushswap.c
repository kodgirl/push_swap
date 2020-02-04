/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pushswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:15:10 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/04 14:25:21 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/bjasper/Desktop/git/includes/push_swap.h"

int		main(int ac, char **av)
{
	t_stack	*stack;
	char	*line;
	t_instr	i_list;
	t_stack	*head;

	if (ac == 1)
		return (0);
	stack = ft_memalloc(sizeof(t_stack));
	if (ft_make_stack(ac, av, stack) == 0)
		return (0);
	num_to_ind(stack->a_stack, stack->lena);
	push_swap(stack);
	// print_stacks(stack);
	printf("Result is %d instructions!\n", stack->result);
	return (0);
}
