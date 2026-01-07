/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:40:31 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/07 10:37:35 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_stack **a, t_stack **b, t_operation_count *op_count,
		bool bench_mode)
{
	push_stack(b, a);
	if (op_count)
	{
		op_count->pa++;
		op_count->total++;
	}
	if (!bench_mode)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, t_operation_count *op_count,
		bool bench_mode)
{
	push_stack(a, b);
	if (op_count)
	{
		op_count->pb++;
		op_count->total++;
	}
	if (!bench_mode)
		write(1, "pb\n", 3);
}
