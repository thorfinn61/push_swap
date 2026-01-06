#include "push_swap.h"
void	chunk_sort(t_stack **a, t_stack **b)
{
	int	*arr;
	int	size;
	int	chunk_size;
	int	start;
	int	end;

	size = stack_size(*a);
	if (size <= 5)
	{
		sort_simple(a, b);
		return ;
	}
	arr = prepare_sorted_array(*a, size);
	chunk_size = (size <= 100) ? 20 : (size / 10 + 1);
	start = 0;
	while (start < size)
	{
		end = start + chunk_size - 1;
		if (end >= size)
			end = size - 1;
		push_chunk_to_b(a, b, arr[start], arr[end]);
		start += chunk_size;
	}
	free(arr);
	move_back_to_a(a, b);
}
