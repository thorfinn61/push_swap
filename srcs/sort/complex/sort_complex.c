/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:40:20 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/07 10:39:44 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex(t_stack **a, t_stack **b, t_operation_count *op_count,
		bool bench_mode)
{
	sort_medium(a, b, op_count, bench_mode);
}
