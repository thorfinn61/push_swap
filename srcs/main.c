/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:41:37 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/07 10:45:54 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h> // For strcmp

int	main(int argc, char **argv)
{
	t_stack				*a;
	t_stack				*b;
	t_operation_count	op_count;
	int					bench_mode;
	int					strat;

	op_count = {0};
	bench_mode = 0;
	strat = 0;
	if (argc < 2)
		return (0);
	a = parse_args(argc, argv, &strat, &bench_mode);
	b = NULL;
	if (!a || is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	if (strat == 1)
		sort_simple(&a, &b, &op_count, bench_mode);
	else if (strat == 2)
		sort_medium(&a, &b, &op_count, bench_mode);
	else if (strat == 3)
		sort_complex(&a, &b, &op_count, bench_mode);
	else
		sort_adaptive(&a, &b, &op_count, bench_mode);
	free_stack(a);
	free_stack(b);
	return (0);
}
