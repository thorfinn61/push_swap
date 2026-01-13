/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:40:20 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/13 11:08:17 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_costs(t_cost *cost, t_stack *a, t_stack *b, int val_b)
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
		cost->a = (size_a - idx_a) * -1;
	else
		cost->a = idx_a;
	if (idx_b > size_b / 2)
		cost->b = (size_b - idx_b) * -1;
	else
		cost->b = idx_b;
}

static int	calc_total(t_cost cost)
{
	if ((cost.a > 0 && cost.b > 0) || (cost.a < 0 && cost.b < 0))
	{
		if (abs(cost.a) > abs(cost.b))
			return (abs(cost.a));
		return (abs(cost.b));
	}
	return (abs(cost.a) + abs(cost.b));
}

int	find_cheapest(t_stack *a, t_stack *b, int *best_ca, int *best_cb)
{
	int		min;
	int		cur;
	t_cost	c;
	t_stack	*tmp;
	int		best_val;

	tmp = b;
	min = INT_MAX;
	best_val = 0;
	while (tmp)
	{
		calculate_costs(&c, a, b, tmp->value);
		cur = calc_total(c);
		if (cur < min)
		{
			min = cur;
			*best_ca = c.a;
			*best_cb = c.b;
			best_val = tmp->value;
		}
		tmp = tmp->next;
	}
	return (best_val);
}

static void	exec_both(t_stack **a, t_stack **b, t_cost *c, t_bench *s)
{
	while (c->a > 0 && c->b > 0)
	{
		rr(a, b, s);
		c->a--;
		c->b--;
	}
	while (c->a < 0 && c->b < 0)
	{
		rrr(a, b, s);
		c->a++;
		c->b++;
	}
}

void	execute_move(t_stack **a, t_stack **b, t_cost c, t_bench *s)
{
	exec_both(a, b, &c, s);
	while (c.a > 0)
	{
		ra(a, s);
		c.a--;
	}
	while (c.a < 0)
	{
		rra(a, s);
		c.a++;
	}
	while (c.b > 0)
	{
		rb(b, s);
		c.b--;
	}
	while (c.b < 0)
	{
		rrb(b, s);
		c.b++;
	}
	pa(a, b, s);
}
