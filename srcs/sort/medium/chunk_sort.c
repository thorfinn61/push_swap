/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:40:02 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/06 18:50:40 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks_to_b(t_chunk_data *data)
{
	int	start;
	int	end;

	start = 0;
	while (start < data->size)
	{
		end = start + data->chunk_size - 1;
		if (end >= data->size)
			end = data->size - 1;
		push_chunk_to_b(data->a, data->b, data->arr[start], data->arr[end]);
		start += data->chunk_size;
	}
}

void	chunk_sort(t_stack **a, t_stack **b)
{
	int				*arr;
	int				size;
	int				chunk_size;
	t_chunk_data	data;

	size = stack_size(*a);
	if (size <= 5)
	{
		sort_simple(a, b);
		return ;
	}
	arr = prepare_sorted_array(*a, size);
	if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = size / 10 + 1;
	data = (t_chunk_data){a, b, arr, size, chunk_size};
	push_chunks_to_b(&data);
	free(arr);
	move_back_to_a(a, b);
}
