/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:40:47 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/07 10:38:02 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a, t_operation_count *op_count, bool bench_mode)
{
	reverse_rotate_stack(a);
	if (op_count)
	{
		op_count->rra++;
		op_count->total++;
	}
	if (!bench_mode)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, t_operation_count *op_count, bool bench_mode)
{
	reverse_rotate_stack(b);
	if (op_count)
	{
		op_count->rrb++;
		op_count->total++;
	}
	if (!bench_mode)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, t_operation_count *op_count,
		bool bench_mode)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	if (op_count)
	{
		op_count->rrr++;
		op_count->total++;
	}
	if (!bench_mode)
		write(1, "rrr\n", 4);
}
