#include "/home/bjasper/Projects/push_swap/includes/push_swap.h"

void	sb(t_swap **stack)
{
	t_swap	*head;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		*stack = (*stack)->next;
		head->next = (*stack)->next;
		(*stack)->next = head;
	}
	printf("sb\n");
}

void	rb(t_swap **stack)
{
	t_swap	*head;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->next = head;
		(*stack) = head->next;
		head->next = NULL;
	}
	printf("rb\n");
}

int		pb(t_stack *stack)
{
	t_swap	*a_head;
	t_swap	*b_head;

	printf("pb\n");
	if (stack->lena == 0)
		return (0);
	a_head = stack->a_stack;
	b_head = stack->b_stack;
	if (stack->lena >= 1 && stack->lenb == 0)
	{
		stack->b_stack = a_head;
		stack->a_stack = stack->a_stack->next;
		stack->b_stack->next = NULL;
	}
	else if (stack->lena >= 1 && stack->lenb > 0)
	{
		stack->b_stack = a_head;
		stack->a_stack = stack->a_stack->next;
		stack->b_stack->next = b_head;
	}
	stack->lenb++;
	stack->lena--;
	return (0);
}

void	rrb(t_swap **stack)
{
	t_swap	*head;
	t_swap	*tmp;

	if (*stack && (*stack)->next)
	{
		head = *stack;
		while ((*stack)->next->next)
			(*stack) = (*stack)->next;
		tmp = (*stack);
		(*stack) = (*stack)->next;
		(*stack)->next = head;
		tmp->next = NULL;
	}
	printf("rrb\n");
}
