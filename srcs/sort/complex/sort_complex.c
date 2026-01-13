/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:40:20 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/13 15:14:48 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sorts 3 elements in A.
*/
static void	sort_three_a(t_stack **a, t_bench *bench)
{
	int	m;
	int	top;
	int	mid;

	if (stack_size(*a) != 3)
		return ;
	m = get_max_val(*a);
	top = (*a)->value;
	mid = (*a)->next->value;
	if (top == m)
		ra(a, bench);
	else if (mid == m)
		rra(a, bench);
	if ((*a)->value > (*a)->next->value)
		sa(a, bench);
}

static void	final_rotation(t_stack **a, t_bench *bench)
{
	int	min_idx;
	int	size_a;

	min_idx = get_index(*a, get_min_val(*a));
	size_a = stack_size(*a);
	if (min_idx < size_a / 2)
	{
		while ((*a)->value != get_min_val(*a))
			ra(a, bench);
	}
	else
	{
		while ((*a)->value != get_min_val(*a))
			rra(a, bench);
	}
}

/*
** Step 1: Push everything to B except 3 numbers.
** Step 2: Sort the 3 remaining in A.
** Step 3: Loop B -> A with cheapest move.
** Step 4: Final rotation to align min at top of A.
*/
void	sort_complex(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size_a;
	int	best_ca;
	int	best_cb;

	size_a = stack_size(*a);
	while (size_a > 3)
	{
		pb(a, b, bench);
		size_a--;
	}
	sort_three_a(a, bench);
	while (*b)
	{
		find_cheapest(*a, *b, &best_ca, &best_cb);
		execute_move(a, b, (t_cost){best_ca, best_cb}, bench);
	}
	final_rotation(a, bench);
}
