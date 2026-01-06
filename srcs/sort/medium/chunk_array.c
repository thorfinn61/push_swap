/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:39:45 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/06 18:39:47 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *stack, int size)
{
	int	*i;
	int	k;

	i = malloc(sizeof(int) * size);
	if (!i)
		error();
	k = 0;
	while (stack && k < size)
	{
		i[k++] = stack->value;
		stack = stack->next;
	}
	return (i);
}

static void	sort_array(int *arr, int n)
{
	int	i;
	int	j;
	int	min;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		min = i;
		j = i + 1;
		while (j < n)
		{
			if (arr[j] < arr[min])
				min = j;
			j++;
		}
		if (min != i)
		{
			tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
		i++;
	}
}

int	*prepare_sorted_array(t_stack *s, int size)
{
	int	*arr;

	arr = stack_to_array(s, size);
	sort_array(arr, size);
	return (arr);
}
