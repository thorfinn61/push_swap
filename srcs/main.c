/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:41:37 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/09 16:42:25 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_sort(t_stack **a, t_stack **b, int strat, t_bench *bench)
{
	if (strat == 1)
		sort_simple(a, b, bench);
	else if (strat == 2)
		sort_medium(a, b, bench);
	else if (strat == 3)
		sort_complex(a, b, bench);
	else
		sort_adaptive(a, b, bench);
}

static void	print_bench(t_bench *b, int strat, double disorder)
{
	int	total;

	total = b->sa + b->sb + b->ss + b->pa + b->pb + b->ra + b->rb + b->rr
		+ b->rra + b->rrb + b->rrr;
	fprintf(stderr, "[bench] disordered: %.2f%%\n", disorder * 100);
	if (strat == 1)
		fprintf(stderr, "[bench] strategy: Simple / O(n^2)\n");
	else if (strat == 2)
		fprintf(stderr, "[bench] strategy: Medium / O(n sqrt(n))\n");
	else if (strat == 3)
		fprintf(stderr, "[bench] strategy: Complex / O(n log n)\n");
	else
		fprintf(stderr, "[bench] strategy: Adaptive / Dynamic\n");
	fprintf(stderr, "[bench] total Ops: %d\n", total);
	fprintf(stderr, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		b->sa, b->sb, b->ss, b->pa, b->pb);
	fprintf(stderr, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		b->ra, b->rb, b->rr, b->rra, b->rrb, b->rrr);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b_stack;
	int		strat;
	t_bench	bench;
	int		bench_mode;
	double	disorder;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv, &strat, &bench_mode);
	b_stack = NULL;
	if (!a || is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	bench = (t_bench){0};
	disorder = compute_disorder(a);
	if (bench_mode)
		do_sort(&a, &b_stack, strat, &bench);
	else
		do_sort(&a, &b_stack, strat, NULL);
	if (bench_mode)
		print_bench(&bench, strat, disorder);
	free_stack(a);
	free_stack(b_stack);
	return (0);
}
