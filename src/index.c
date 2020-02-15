/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 20:19:36 by bjasper           #+#    #+#             */
/*   Updated: 2020/02/15 15:54:24 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_index(t_swap *stack, int *tab, int len)
{
	int		i;
	t_swap	*head;

	i = 0;
	head = stack;
	while (i < len)
	{
		while (stack->next != NULL)
		{
			if (stack->num == tab[i])
			{
				stack->index = i;
				break ;
			}
			stack = stack->next;
		}
		if (stack->num == tab[i])
			stack->index = i;
		++i;
		stack = head;
	}
}

void	ft_sort(int *tab, int len)
{
	int i;
	int tmp;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			++i;
	}
}

void	num_to_ind(t_swap *stack, int len)
{
	int		*tab;
	int		i;
	t_swap	*head;

	tab = malloc(sizeof(int) * len);
	head = stack;
	i = 0;
	while (i < len)
	{
		tab[i] = stack->num;
		if (stack->next != NULL)
			stack = stack->next;
		++i;
	}
	stack = head;
	ft_sort(tab, len);
	find_index(stack, tab, len);
	free(tab);
}
