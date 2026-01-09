/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:39:35 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/09 18:13:36 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_adaptive(t_stack **a, t_stack **b, t_bench *bench)
{
	int		size;
	double	disorder;

	if (!a || !*a)
		return (0);
	size = stack_size(*a);
	disorder = compute_disorder(*a);
	if (size <= 5 || disorder < 0.2)
	{
		sort_simple(a, b, bench);
		return (1);
	}
	else if (disorder < 0.5)
	{
		sort_medium(a, b, bench);
		return (2);
	}
	else
	{
		sort_complex(a, b, bench);
		return (3);
	}
}
