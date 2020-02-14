/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:04:45 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/14 16:04:59 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	f_lstadd(t_swap **stack, t_swap *new)
{
	if (!*stack)
		new->next = NULL;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

int		is_sorted(t_stack *stack, int flag)
{
	t_swap *head;

	head = stack->a_stack;
	if (stack->lenb != 0)
	{
		if (flag == 1)
			write(1, "KO\n", 3);
		return (0);
	}
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

int		is_dubl(t_swap *a_stack)
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
				write(1, ERROR_DUBL, 20);
				return(1);
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
	int		error;
	char	**big_str;
	int		i;
	int		num;

	error = 0;
	while (ac)
	{
		big_str = ft_strsplit(av[ac], ' ');
		i = massive_len(big_str);
		while (i > 0)
		{
			--i;
			num = f_atoi(big_str[i], &error);
			if (error == 1)
				return (0);
			if (stack->lena == 0)
			{
				stack->a_stack = f_lstnew(num);
				stack->lena++;
			}
			else
			{
				new = f_lstnew(num);
				f_lstadd(&stack->a_stack, new);
				stack->lena++;
			}
		}
		del_double_massive(big_str);
		--ac;
	}
	if (is_dubl(stack->a_stack))
		return (0);
	return (1);
}
