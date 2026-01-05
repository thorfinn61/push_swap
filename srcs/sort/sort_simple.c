#include "push_swap.h"

static int	find_min_index(t_stack *stack)
{
	int idx;
	int min_idx;
	int min_val;
	int i;

	if (!stack)
		return (0);
	i = 0;
	idx = 0;
	min_idx = 0;
	min_val = stack->value;
	while (stack)
	{
		if (stack->value < min_val)
		{
			min_val = stack->value;
			min_idx = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_idx);
}

static void	push_min_to_b(t_stack **a, t_stack **b)
{
	int size;
	int min_idx;

	size = stack_size(*a);
	if (size == 0)
		return ;
	min_idx = find_min_index(*a);
	if (min_idx <= size / 2)
	{
		while (min_idx-- > 0)
			ra(a);
	}
	else
	{
		min_idx = size - min_idx;
		while (min_idx-- > 0)
			rra(a);
	}
	pb(a, b);
}

void	sort_simple(t_stack **a, t_stack **b )
{
	int size;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	while (size > 0)
	{
		push_min_to_b(a, b);
		size--;
	}
	while (stack_size(*b) > 0)
		pa(a, b);
}
