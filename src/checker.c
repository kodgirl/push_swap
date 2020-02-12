/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:04:45 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/12 18:57:31 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_sorted(t_stack *stack, int flag)
{
	t_swap *head;

	head = stack->a_stack;
	if (stack->lenb != 0)
		return (0);
	while (stack->a_stack->next)
	{
		if (stack->a_stack->num >= stack->a_stack->next->num)
		{
			stack->a_stack = head;
			if (flag == 1)
				write(1, "KO\n", 3);
			return (0);
		}
		stack->a_stack = stack->a_stack->next;
	}
	stack->a_stack = head;
	if (flag == 1)
		write(1, "OK\n", 3);
	return (1);
}

int		is_dubl(t_swap *a_stack, char **error)
{
	t_swap	*tmp;
	t_swap	*head;

	tmp = a_stack;
	head = a_stack;
	while (tmp)
	{
		a_stack = tmp->next;
		while (a_stack)
		{
			if (tmp->num == a_stack->num)
			{
				*error = ERROR_DUBL;
				return (0);
			}
			a_stack = a_stack->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int		massive_len(char **str)
{
	int		res;

	res = 0;
	while (str[res] != NULL)
		++res;
	return (res);
}

int		ft_make_stack(int ac, char **av, t_stack *stack)
{
	t_swap	*new;
	char	*error;
	char	**big_str;
	int		i;

	error = NULL;
	stack->a_stack = ft_memalloc(sizeof(t_swap));
	stack->b_stack = ft_memalloc(sizeof(t_swap));
	while (ac)
	{
		big_str = ft_memalloc(strlen(av[ac]) * sizeof(char));
		big_str = ft_strsplit(av[ac], ' ');
		i = massive_len(big_str);
		while (i > 0)
		{
			--i;
			if (stack->lena == 0)
			{
				stack->a_stack = f_lstnew(f_atoi(big_str[i], &error));
				stack->lena++;
			}
			else
			{
				new = f_lstnew(f_atoi(big_str[i], &error));
				f_lstadd(&stack->a_stack, new);
				stack->lena++;
			}
		}
		ft_strdel(big_str);
		--ac;
	}
	if (error == NULL)
		is_dubl(stack->a_stack, &error);
	if (error)
	{
		printf("%s", error);
		return (0);
	}
	return (1);
}
