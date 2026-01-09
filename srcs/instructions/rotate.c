/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:40:37 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/09 17:13:11 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack **stack)
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

void	ra(t_stack **a, t_bench *bench)
{
	rotate_stack(a);
	if (!bench)
		write(1, "ra\n", 3);
	if (bench)
		bench->ra++;
}

void	rb(t_stack **b, t_bench *bench)
{
	rotate_stack(b);
	if (!bench)
		write(1, "rb\n", 3);
	if (bench)
		bench->rb++;
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	rotate_stack(a);
	rotate_stack(b);
	if (!bench)
		write(1, "rr\n", 3);
	if (bench)
		bench->rr++;
}
