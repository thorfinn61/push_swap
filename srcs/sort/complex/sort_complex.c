/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elyesa1 <Elyesa1@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:40:20 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/16 00:49:41 by Elyesa1          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	restore_stack(t_stack **stack, t_bench *bench, int count, int type)
{
	int	i;

	i = 0;
	if (stack_size(*stack) == count)
		return ;
	while (i < count)
	{
		if (type == 0)
			rra(stack, bench);
		else
			rrb(stack, bench);
		i++;
	}
}

static void	quicksort_b(t_stack **a, t_stack **b, int count, t_bench *bench);

static void	quicksort_a(t_stack **a, t_stack **b, int count, t_bench *bench)
{
	int	pivot;
	int	pushed;
	int	rotated;
	int	i;

	if (qs_handle_base_a(a, count, bench))
		return ;
	pivot = qs_get_pivot(*a, count);
	pushed = 0;
	rotated = 0;
	i = count;
	while (i--)
	{
		if ((*a)->value < pivot)
			(pb(a, b, bench), pushed++);
		else
			(ra(a, bench), rotated++);
	}
	restore_stack(a, bench, rotated, 0);
	quicksort_a(a, b, rotated, bench);
	quicksort_b(a, b, pushed, bench);
}

static void	quicksort_b(t_stack **a, t_stack **b, int count, t_bench *bench)
{
	int	pivot;
	int	pushed;
	int	rotated;
	int	i;

	if (qs_handle_base_b(a, b, count, bench))
		return ;
	pivot = qs_get_pivot(*b, count);
	pushed = 0;
	rotated = 0;
	i = count;
	while (i--)
	{
		if ((*b)->value >= pivot)
			(pa(a, b, bench), pushed++);
		else
			(rb(b, bench), rotated++);
	}
	quicksort_a(a, b, pushed, bench);
	restore_stack(b, bench, rotated, 1);
	quicksort_b(a, b, rotated, bench);
}

void	sort_complex(t_stack **a, t_stack **b, t_bench *bench)
{
	quicksort_a(a, b, stack_size(*a), bench);
}
