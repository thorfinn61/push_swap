#include "push_swap.h"

double	disorder(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	double mistakes;
	double total;
	if (!a || !a->next)
		return (0.0);
	
	mistakes = 0;
	total = 0;

	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / total);
}