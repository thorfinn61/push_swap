/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:40:20 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/12 15:26:19 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_costs(int *cost_a, int *cost_b, t_stack *a, t_stack *b,
		int val_b)
{
	int	size_a;
	int	size_b;
	int	idx_a;
	int	idx_b;

	size_a = stack_size(a);
	size_b = stack_size(b);
	idx_a = get_target_pos(a, val_b);
	idx_b = get_index(b, val_b);
	if (idx_a > size_a / 2)
		*cost_a = (size_a - idx_a) * -1;
	else
		*cost_a = idx_a;
	if (idx_b > size_b / 2)
		*cost_b = (size_b - idx_b) * -1;
	else
		*cost_b = idx_b;
}

/*
** Finds the cheapest element to move from B to A.
** Returns the value of the cheapest element.
** Updates the pointers to costs via arguments.
*/
int	find_cheapest(t_stack *a, t_stack *b, int *best_ca, int *best_cb)
{
	int		min_total;
	int		ca;
	int		cb;
	int		curr_total;
	int		val_best;
	t_stack	*tmp_b;

	tmp_b = b;
	min_total = INT_MAX;
	val_best = 0;
	while (tmp_b)
	{
		calculate_costs(&ca, &cb, a, b, tmp_b->value);
		if ((ca > 0 && cb > 0) || (ca < 0 && cb < 0))
			curr_total = abs(ca) > abs(cb) ? abs(ca) : abs(cb);
		else
			curr_total = abs(ca) + abs(cb);
		if (curr_total < min_total)
		{
			min_total = curr_total;
			*best_ca = ca;
			*best_cb = cb;
			val_best = tmp_b->value;
		}
		tmp_b = tmp_b->next;
	}
	return (val_best);
}

void	execute_move(t_stack **a, t_stack **b, int ca, int cb, t_bench *s)
{
	while (ca > 0 && cb > 0)
	{
		rr(a, b, s);
		ca--;
		cb--;
	}
	while (ca < 0 && cb < 0)
	{
		rrr(a, b, s);
		ca++;
		cb++;
	}
	while (ca > 0)
	{
		ra(a, s);
		ca--;
	}
	while (ca < 0)
	{
		rra(a, s);
		ca++;
	}
	while (cb > 0)
	{
		rb(b, s);
		cb--;
	}
	while (cb < 0)
	{
		rrb(b, s);
		cb++;
	}
	pa(a, b, s);
}
