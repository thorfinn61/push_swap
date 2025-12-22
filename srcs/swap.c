#include "push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack *first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return;
	first = *stack;
	second = first->next;

	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a)
{
	swap_stack(a);
	write (1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap_stack(b);
	write (1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap_stack(a);
	swap_stack(b);
	write (1, "ss\n", 3);
}