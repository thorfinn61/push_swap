/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:40:11 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/07 10:39:36 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_medium(t_stack **a, t_stack **b, t_operation_count *op_count,
		bool bench_mode)
{
	chunk_sort(a, b, op_count, bench_mode);
}
