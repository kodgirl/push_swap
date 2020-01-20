#include "../includes/push_swap.h"

void f_lstadd(t_swap **stack, t_swap *new)
{
	if (!stack)
		new->next = NULL;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

int	ft_make_stack(int ac, char **av, t_swap **a_stack)
{
	t_swap	*new;
	char	*error;

	ac--;
	error = NULL;
	*a_stack = f_lstnew(f_atoi(av[ac], &error));
	ac--;
	while (ac)
	{
		new = f_lstnew(f_atoi(av[ac], &error));
		--ac;
		f_lstadd(a_stack, new);
	}
	if (error)
	{
		printf("%s", error);					//change to putstr
		return (0);
	}
	return (1);
}

int is_sorted(t_swap *a_stack)
{
	while (a_stack->next)
	{
		if (a_stack->num >= a_stack->next->num)
		{
			printf("KO\n");
			return (0);
		}
		a_stack = a_stack->next;
	}
	printf("OK\n");
	return (0);
}

int	is_dubl(t_swap *a_stack)
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
				printf("%s", ERROR_DUBL);
				return (1);
			}
			a_stack = a_stack->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int main(int ac, char **av)
{
	t_swap	*a_stack;
	
	a_stack = NULL;
	if (ac == 1)
		return (0);
	if (ft_make_stack(ac, av, &a_stack) == 0)
		return (0);
	if (is_dubl(a_stack))
		return (0);
	is_sorted(a_stack);	
	while (a_stack->next)					//check
	{
		printf("%d ", a_stack->num);
		a_stack = a_stack->next;
	}
	printf("%d ", a_stack->num);			//
	return (0);
}
