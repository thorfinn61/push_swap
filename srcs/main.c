/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:41:37 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/09 17:42:27 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_sort(t_stack **a, t_stack **b, int strat, t_bench *bench)
{
	if (strat == 1)
	{
		sort_simple(a, b, bench);
		return (1);
	}
	else if (strat == 2)
	{
		sort_medium(a, b, bench);
		return (2);
	}
	else if (strat == 3)
	{
		sort_complex(a, b, bench);
		return (3);
	}
	else
		return (sort_adaptive(a, b, bench));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b_stack;
	int		strat;
	int		used_strat;
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
	used_strat = strat;
	if (bench_mode)
		used_strat = do_sort(&a, &b_stack, strat, &bench);
	else
		do_sort(&a, &b_stack, strat, NULL);
	if (bench_mode)
		print_bench(&bench, strat, used_strat, disorder);
	free_stack(a);
	free_stack(b_stack);
	return (0);
}
