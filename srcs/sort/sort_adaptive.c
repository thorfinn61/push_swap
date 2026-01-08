/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:39:35 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/08 23:00:00 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack **a, t_stack **b)
{
	int		size;
	double	disorder;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	disorder = compute_disorder(*a);
	if (size <= 5)
		sort_simple(a, b);
	else if (disorder < 0.2)
		sort_simple(a, b);
	else if (disorder < 0.5)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}
