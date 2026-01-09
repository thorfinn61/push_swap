/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:41:00 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/09 18:08:06 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_strategy(int strat, int used_strat)
{
	if (strat == 0)
	{
		ft_dprintf(2, "[bench] strategy: Adaptive / ");
		if (used_strat == 1)
			ft_dprintf(2, "O(n^2)\n");
		else if (used_strat == 2)
			ft_dprintf(2, "O(n√n)\n");
		else
			ft_dprintf(2, "O(n log n)\n");
	}
	else if (strat == 1)
		ft_dprintf(2, "[bench] strategy: Simple / O(n^2)\n");
	else if (strat == 2)
		ft_dprintf(2, "[bench] strategy: Medium / O(n√n)\n");
	else if (strat == 3)
		ft_dprintf(2, "[bench] strategy: Complex / O(n log n)\n");
}

static void	print_ops_details(t_bench *b)
{
	ft_dprintf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		b->sa, b->sb, b->ss, b->pa, b->pb);
	ft_dprintf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		b->ra, b->rb, b->rr, b->rra, b->rrb, b->rrr);
}

void	print_bench(t_bench *b, int strat, int used_strat, double disorder)
{
	int	total;
	int	int_part;
	int	dec_part;

	total = b->sa + b->sb + b->ss + b->pa + b->pb + b->ra + b->rb + b->rr
		+ b->rra + b->rrb + b->rrr;
	int_part = (int)(disorder * 100);
	dec_part = (int)((disorder * 100 - int_part) * 100);
	ft_dprintf(2, "[bench] disordered: %d.", int_part);
	if (dec_part < 10)
		ft_dprintf(2, "0");
	ft_dprintf(2, "%d%%\n", dec_part);
	print_strategy(strat, used_strat);
	ft_dprintf(2, "[bench] Total Ops: %d\n", total);
	print_ops_details(b);
}
