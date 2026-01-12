/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 18:40:20 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/12 15:24:56 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target_pos(t_stack *a, int val_b)
{
	int		target_idx;
	int		curr_idx;
	long	closest_diff;
	t_stack	*curr_a;

	target_idx = -1;
	curr_idx = 0;
	closest_diff = LONG_MAX;
	curr_a = a;
	while (curr_a)
	{
		if (curr_a->value > val_b && (curr_a->value - val_b) < closest_diff)
		{
			closest_diff = curr_a->value - val_b;
			target_idx = curr_idx;
		}
		curr_a = curr_a->next;
		curr_idx++;
	}
	if (target_idx != -1)
		return (target_idx);
	return (get_index(a, get_min_val(a)));
}
