/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:37:01 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/07 10:42:56 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_benchmark(t_operation_count *op_count, double disorder,
		const char *strategy, const char *complexity)
{
	fprintf(stderr, "[bench] Disorder: %.2f%%\n", disorder * 100);
	fprintf(stderr, "[bench] Strategy: %s\n", strategy);
	fprintf(stderr, "[bench] Complexity: %s\n", complexity);
	fprintf(stderr, "[bench] Total operations: %d\n", op_count->total);
	fprintf(stderr, "[bench] Operation counts:\n");
	fprintf(stderr, "[bench] sa: %d\n", op_count->sa);
	fprintf(stderr, "[bench] sb: %d\n", op_count->sb);
	fprintf(stderr, "[bench] ss: %d\n", op_count->ss);
	fprintf(stderr, "[bench] pa: %d\n", op_count->pa);
	fprintf(stderr, "[bench] pb: %d\n", op_count->pb);
	fprintf(stderr, "[bench] ra: %d\n", op_count->ra);
	fprintf(stderr, "[bench] rb: %d\n", op_count->rb);
	fprintf(stderr, "[bench] rr: %d\n", op_count->rr);
	fprintf(stderr, "[bench] rra: %d\n", op_count->rra);
	fprintf(stderr, "[bench] rrb: %d\n", op_count->rrb);
	fprintf(stderr, "[bench] rrr: %d\n", op_count->rrr);
}

void	print_benchmark_wrapper(t_operation_count *op_count, double disorder,
		const char *strategy, const char *complexity)
{
	print_benchmark(op_count, disorder, strategy, complexity);
}
