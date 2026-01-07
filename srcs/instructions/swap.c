/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:40:53 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/07 10:38:08 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a, t_operation_count *op_count, bool bench_mode)
{
	swap_stack(a);
	if (op_count)
	{
		op_count->sa++;
		op_count->total++;
	}
	if (!bench_mode)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, t_operation_count *op_count, bool bench_mode)
{
	swap_stack(b);
	if (op_count)
	{
		op_count->sb++;
		op_count->total++;
	}
	if (!bench_mode)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, t_operation_count *op_count,
		bool bench_mode)
{
	swap_stack(a);
	swap_stack(b);
	if (op_count)
	{
		op_count->ss++;
		op_count->total++;
	}
	if (!bench_mode)
		write(1, "ss\n", 3);
}
