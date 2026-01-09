/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:40:53 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/09 16:50:57 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack **stack)
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

void	sa(t_stack **a, t_bench *bench)
{
	swap_stack(a);
	if(!bench)
		write(1, "sa\n", 3);
	if (bench)
		bench->sa++;
}

void	sb(t_stack **b, t_bench *bench)
{
	swap_stack(b);
	if(!bench)
		write(1, "sb\n", 3);
	if (bench)
		bench->sb++;
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	swap_stack(a);
	swap_stack(b);
	if(!bench)
		write(1, "ss\n", 3);
	if (bench)
		bench->ss++;
}
