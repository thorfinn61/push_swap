/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:39:54 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/07 10:42:48 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Trouver l'a valeur du chunk a push vers b
static int	find_next_in_chunk(t_stack *stack, int chunk_min, int chunk_max)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value >= chunk_min && stack->value <= chunk_max)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

// trouver la valeur max pour repush vers a
static int	find_max_pos(t_stack *stack)
{
	int	max_value;
	int	pos;
	int	max_pos;

	if (!stack)
		return (-1);
	pos = 0;
	max_pos = 0;
	max_value = stack->value;
	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_pos = pos;
		}
		stack = stack->next;
		pos++;
	}
	return (max_pos);
}

void	push_chunk_to_b(t_chunk_params *params, t_operation_count *op_count,
		bool bench_mode)
{
	int	pos;

	pos = find_next_in_chunk(*(params->stack_a), params->chunk_min,
			params->chunk_max);
	while (pos != -1)
	{
		if (pos <= stack_size(*(params->stack_a)) / 2)
			while (pos-- > 0)
				ra(params->stack_a, op_count, bench_mode);
		else
			while (pos++ < stack_size(*(params->stack_a)))
				rra(params->stack_a, op_count, bench_mode);
		pb(params->stack_a, params->stack_b, op_count, bench_mode);
		pos = find_next_in_chunk(*(params->stack_a), params->chunk_min,
				params->chunk_max);
	}
}

void	move_back_to_a(t_stack **stack_a, t_stack **stack_b,
		t_operation_count *op_count, bool bench_mode)
{
	int	pos;

	while (stack_size(*stack_b) > 0)
	{
		pos = find_max_pos(*stack_b);
		if (pos <= stack_size(*stack_b) / 2)
			while (pos-- > 0)
				rb(stack_b, op_count, bench_mode);
		else
			while (pos++ < stack_size(*stack_b))
				rrb(stack_b, op_count, bench_mode);
		pa(stack_a, stack_b, op_count, bench_mode);
	}
}
