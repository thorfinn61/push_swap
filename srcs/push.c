#include "push_swap.h"

static void	push_stack(t_stack **src, t_stack **dst)
{
	t_stack *tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push_stack(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push_stack(a, b);
	write(1, "pb\n", 3);
}
