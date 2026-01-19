/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:39:17 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/19 13:55:05 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_index(t_stack *stack)
{
	int	min_value;
	int	min_index;
	int	current_index;

	if (!stack)
		return (0);
	min_value = stack->value;
	min_index = 0;
	current_index = 0;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_index = current_index;
		}
		stack = stack->next;
		current_index++;
	}
	return (min_index);
}

static void	push_min_to_b(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	min_index;

	size = stack_size(*a);
	if (size <= 1)
		return ;
	min_index = find_min_index(*a);
	if (min_index <= size / 2)
	{
		while (min_index-- > 0)
			ra(a, bench);
	}
	else
	{
		min_index = size - min_index;
		while (min_index-- > 0)
			rra(a, bench);
	}
	pb(a, b, bench);
}

void	sort_simple(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, bench);
		return ;
	}
	if (size == 3)
	{
		qs_sort_three_a(a, bench);
		return ;
	}
	while (size-- > 0)
		push_min_to_b(a, b, bench);
	while (*b)
		pa(a, b, bench);
}
