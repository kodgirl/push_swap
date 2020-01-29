/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjasper <bjasper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:04:45 by bjasper           #+#    #+#             */
/*   Updated: 2020/01/29 19:41:43 by bjasper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/bjasper/Desktop/git/includes/push_swap.h"

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

int		is_sorted(t_stack *stack)
{
	t_swap *head;

	head = stack->a_stack;
	if (stack->lenb != 0)
	{
		printf("KO\n");
		return (0);
	}
	while (stack->a_stack->next)
	{
		if (stack->a_stack->num >= stack->a_stack->next->num)
		{
			printf("KO\n");
			stack->a_stack = head;
			return (0);
		}
		stack->a_stack = stack->a_stack->next;
	}
	stack->a_stack = head;
	printf("OK\n");
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

int		ft_make_stack(int ac, char **av, t_stack *stack)
{
	t_swap	*new;
	char	*error;

	ac--;
	error = NULL;
	stack->lena = ac;
	stack->a_stack = ft_memalloc(sizeof(t_swap));
	stack->b_stack = ft_memalloc(sizeof(t_swap));
	stack->a_stack = f_lstnew(f_atoi(av[ac], &error));
	ac--;
	while (ac)
	{
		new = f_lstnew(f_atoi(av[ac], &error));
		--ac;
		f_lstadd(&stack->a_stack, new);
	}
	is_dubl(stack->a_stack, &error);
	if (error)
	{
		printf("%s", error);
		return (0);
	}
	return (1);
}

void	print_stacks(t_stack *stack)
{
	t_swap *a_head;
	t_swap *b_head;
	int		a;
	int		b;
	
	a_head = stack->a_stack;
	b_head = stack->b_stack;
	a = stack->lena;
	b = stack->lenb;
	printf("lena: %d\n", a);
	printf("lenb: %d\n", b);
	while (a > 1)
	{
		printf("%d\n", stack->a_stack->num);
		stack->a_stack = stack->a_stack->next;
		--a;
	}
	if (a == 1)
		printf("%d\n", stack->a_stack->num);
	printf("\n\n");
	while (b > 1)
	{
		printf("%d\n", stack->b_stack->num);
		stack->b_stack = stack->b_stack->next;
		--b;
	}
	if (b == 1)
		printf("%d\n", stack->b_stack->num);
	stack->a_stack = a_head;
	stack->b_stack = b_head;
}