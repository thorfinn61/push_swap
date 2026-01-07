/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:40:37 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/07 10:37:45 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_stack **a, t_operation_count *op_count, bool bench_mode)
{
	rotate(a);
	if (op_count)
	{
		op_count->ra++;
		op_count->total++;
	}
	if (!bench_mode)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, t_operation_count *op_count, bool bench_mode)
{
	rotate(b);
	if (op_count)
	{
		op_count->rb++;
		op_count->total++;
	}
	if (!bench_mode)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, t_operation_count *op_count,
		bool bench_mode)
{
	rotate(a);
	rotate(b);
	if (op_count)
	{
		op_count->rr++;
		op_count->total++;
	}
	if (!bench_mode)
		write(1, "rr\n", 3);
}
