/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:41:37 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/06 18:41:41 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	b = NULL;
	printf("disorder = %f\n", compute_disorder(a));
	if (!a || is_sorted(a))
	{
		free_stack(a);
		return (0);
	}
	sort_adaptive(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
