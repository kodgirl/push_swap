#include "/home/bjasper/Projects/push_swap/includes/push_swap.h"

void	ss(t_stack *stack)
{
	sa(stack->a_stack);
	sb(stack->b_stack);	
	printf("ss\n");
}

void	rr(t_stack *stack)
{
	ra(stack->a_stack);
	rb(stack->b_stack);
	printf("rr\n");
}

void	rrr(t_stack *stack)
{
	rra(stack->a_stack);
	rrb(stack->b_stack);
	printf("rrr\n");
}
