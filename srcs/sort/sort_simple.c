#include "push_swap.h"

void	sort_simple(t_stack **a, t_stack **b )
{
	int size;

	size = stack_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
}