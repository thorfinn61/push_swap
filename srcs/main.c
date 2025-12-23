#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	if (argc < 2)
		return (0);

	a = parse_args(argc, argv);
	b = NULL;

	if (!a || is_sorted(a))
	{
		free_stack(a);
		return (0);
	}

	size = stack_size(a);
	if (size == 2)
		sort_two(&a);
	else if (size == 3)
		sort_three(&a);
	else if (size <= 5)
		sort_five(&a, &b);

	free_stack(a);
	free_stack(b);
	return (0);
}
