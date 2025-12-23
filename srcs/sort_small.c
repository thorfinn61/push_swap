#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_stack **a)
{
	int		f;
	int		s;
	int		t;

	f = (*a)->value;
	s = (*a)->next->value;
	t = (*a)->next->next->value;

	if (f < s && s < t)
		return ;
	else if (f > s && s < t && f < t)
		sa(a);
	else if (f > s && s > t)
	{
		sa(a);
		rra(a);
	}
	else if (f < s && s > t && f < t)
		rra(a);
	else if (f > s && s < t && f > t)
		ra(a);
}
static int find_min(t_stack *a)
{
	int		min;

	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}
void	sort_five(t_stack **a, t_stack **b)
{
	int		min;

	while (stack_size(*a) > 3)
	{
		min = find_min(*a);
		while ((*a)->value != min)
			ra(a);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}