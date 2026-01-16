/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elyesa1 <Elyesa1@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:30:00 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/16 01:05:36 by Elyesa1          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	qs_is_sorted(t_stack *stack, int count)
{
	int	i;

	i = 0;
	while (i < count - 1 && stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

void	qs_sort_three_a(t_stack **a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	if (stack_size(*a) < 3)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && third > first)
		sa(a, bench);
	else if (first > second && second > third && third < first)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (first > second && second < third && third < first)
		ra(a, bench);
	else if (first < second && second > third && third > first)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (first < second && second > third && third < first)
		rra(a, bench);
}

int	qs_handle_base_a(t_stack **a, int count, t_bench *bench)
{
	if (qs_is_sorted(*a, count))
		return (1);
	if (count == 2)
	{
		sa(a, bench);
		return (1);
	}
	if (count == 3 && stack_size(*a) == 3)
	{
		qs_sort_three_a(a, bench);
		return (1);
	}
	return (0);
}

int	qs_handle_base_b(t_stack **a, t_stack **b, int count, t_bench *bench)
{
	if (count == 0)
		return (1);
	if (count <= 2)
	{
		if (count == 2 && (*b)->value < (*b)->next->value)
			sb(b, bench);
		while (count--)
			pa(a, b, bench);
		return (1);
	}
	return (0);
}
