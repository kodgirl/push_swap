/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:11:05 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/29 13:11:09 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	t_stack	*stack;
	char	*line;
	int		size;
	t_instr	i_list;

	if (ac == 1)
		return (0);
	stack = ft_memalloc(sizeof(t_stack));
	if (ft_make_stack(ac, av, stack) == 0)
		return (0);
	make_instr(&i_list);
	while ((size = get_next_line(0, &line)) > 0)
	{
		if (read_instruct(line, stack, &i_list) == 0)
			return (0);
	}
	if (size < 0)
		printf("%s", ERROR_BAD_INSTRUCT);
	is_sorted(stack);
	printf("lena: %d\n", stack->lena);
	printf("lenb: %d\n", stack->lenb);
	while (stack->lena > 1)
	{
		printf("%d\n", stack->a_stack->num);
		stack->a_stack = stack->a_stack->next;
		--stack->lena;
	}
	if (stack->lena == 1)
		printf("%d\n", stack->a_stack->num);
	printf("\n\n");
	while (stack->lenb > 1)
	{
		printf("%d\n", stack->b_stack->num);
		stack->b_stack = stack->b_stack->next;
		--stack->lenb;
	}
	if (stack->lenb == 1)
		printf("%d\n", stack->b_stack->num);
	return (0);
}
