#include "push_swap.h"

void	sort_adaptive(t_stack **a, t_stack **b)
{
	double disorder;

	disorder = compute_disorder(*a);
	if (disorder < 0.15)
		sort_simple(a, b);
	else if (disorder < 0.40)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}