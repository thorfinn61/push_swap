/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:40:02 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/07 10:42:37 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunks_to_b(t_chunk_data *data, t_operation_count *op_count,
		bool bench_mode)
{
	int				start;
	int				end;
	t_chunk_params	params;

	params = (t_chunk_params){data->a, data->b, 0, 0};
	start = 0;
	while (start < data->size)
	{
		end = start + data->chunk_size - 1;
		if (end >= data->size)
			end = data->size - 1;
		params.chunk_min = data->arr[start];
		params.chunk_max = data->arr[end];
		push_chunk_to_b(&params, op_count, bench_mode);
		start += data->chunk_size;
	}
}

void	chunk_sort(t_stack **a, t_stack **b, t_operation_count *op_count,
		bool bench_mode)
{
	int				*arr;
	int				size;
	int				chunk_size;
	t_chunk_data	data;

	size = stack_size(*a);
	if (size <= 5)
	{
		sort_simple(a, b, op_count, bench_mode);
		return ;
	}
	arr = prepare_sorted_array(*a, size);
	if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = size / 10 + 1;
	data = (t_chunk_data){a, b, arr, size, chunk_size};
	push_chunks_to_b(&data, op_count, bench_mode);
	free(arr);
	move_back_to_a(a, b, op_count, bench_mode);
	if (bench_mode)
		print_benchmark_wrapper(op_count, 0.5, "Medium", "O(n log n)");
}
