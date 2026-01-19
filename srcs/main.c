/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:41:37 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/19 11:28:36 by elsahin          ###   ########.fr       */
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

static void	run_sort_logic(t_stack **a, int strat, int bench_mode)
{
	t_stack	*b;
	t_bench	bench;
	int		used;
	double	disorder;

	b = NULL;
	bench = (t_bench){0};
	disorder = compute_disorder(*a);
	used = strat;
	if (bench_mode)
	{
		if (!is_sorted(*a))
			used = do_sort(a, &b, strat, &bench);
		print_bench(&bench, strat, used, disorder);
	}
	else
		do_sort(a, &b, strat, NULL);
	free_stack(*a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		strat;
	int		bench_mode;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv, &strat, &bench_mode);
	if (!a || (is_sorted(a) && !bench_mode))
	{
		free_stack(a);
		return (0);
	}
	run_sort_logic(&a, strat, bench_mode);
	return (0);
}
