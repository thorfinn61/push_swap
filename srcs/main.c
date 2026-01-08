/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:41:37 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/08 23:00:00 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_sort(t_stack **a, t_stack **b, int strat)
{
	if (strat == 1)
		sort_simple(a, b);
	else if (strat == 2)
		sort_medium(a, b);
	else if (strat == 3)
		sort_complex(a, b);
	else
		sort_adaptive(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		strat;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv, &strat);
	b = NULL;
	if (!a || is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	do_sort(&a, &b, strat);
	free_stack(a);
	free_stack(b);
	return (0);
}
