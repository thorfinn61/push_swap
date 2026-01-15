/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elyesa1 <Elyesa1@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:20:00 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/16 00:35:01 by Elyesa1          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*qs_stack_to_array(t_stack *stack, int count)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * count);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < count && stack)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (arr);
}

static void	qs_sort_int_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	qs_get_pivot(t_stack *stack, int count)
{
	int	*arr;
	int	pivot;

	arr = qs_stack_to_array(stack, count);
	if (!arr)
		return (0);
	qs_sort_int_array(arr, count);
	pivot = arr[count / 2];
	free(arr);
	return (pivot);
}
