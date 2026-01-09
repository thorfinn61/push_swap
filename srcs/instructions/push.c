/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:40:31 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/09 16:51:10 by elsahin          ###   ########.fr       */
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

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	push_stack(b, a);
	if(!bench)
		write(1, "pa\n", 3);
	if (bench)
		bench->pa++;
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	push_stack(a, b);
	if(!bench)
		write(1, "pb\n", 3);
	if (bench)
		bench->pb++;
}
