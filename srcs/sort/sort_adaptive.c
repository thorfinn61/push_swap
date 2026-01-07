/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:39:35 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/07 10:38:32 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack **a, t_stack **b, t_operation_count *op_count,
		bool bench_mode)
{
	double	disorder;

	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		sort_simple(a, b, op_count, bench_mode);
	else if (disorder < 0.5)
		sort_medium(a, b, op_count, bench_mode);
	else
		sort_complex(a, b, op_count, bench_mode);
	if (bench_mode)
		print_benchmark(op_count, disorder, "Adaptive", "O(n log n)");
}
