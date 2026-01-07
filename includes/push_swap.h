/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:41:20 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/07 10:45:30 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h> // For boolean type
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_chunk_data
{
	t_stack			**a;
	t_stack			**b;
	int				*arr;
	int				size;
	int				chunk_size;
}					t_chunk_data;

typedef struct s_chunk_params
{
	t_stack			**stack_a;
	t_stack			**stack_b;
	int				chunk_min;
	int				chunk_max;
}					t_chunk_params;

typedef struct s_operation_count
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_operation_count;

void				error(void);

// Parser
t_stack				*parse_args(int argc, char **argv, int *strat, int *bench);
char				**ft_split(char const *s, char c);
int					is_valid_number(char *str);
long				ft_atol(const char *str);
void				free_split(char **split);
int					ft_strncmp(char *s1, char *s2, int n);
int					parse_flag(int ac, char **av, int *strat, int *bench);

// Stack
t_stack				*stack_new(int value);
void				stack_add_back(t_stack **stack, t_stack *new);
int					stack_size(t_stack *stack);
int					is_sorted(t_stack *stack);
void				free_stack(t_stack *stack);

// Instruction
void				pa(t_stack **a, t_stack **b, t_operation_count *op_count,
						bool bench_mode);
void				pb(t_stack **a, t_stack **b, t_operation_count *op_count,
						bool bench_mode);
void				sa(t_stack **a, t_operation_count *op_count,
						bool bench_mode);
void				sb(t_stack **b, t_operation_count *op_count,
						bool bench_mode);
void				ss(t_stack **a, t_stack **b, t_operation_count *op_count,
						bool bench_mode);

void				ra(t_stack **a, t_operation_count *op_count,
						bool bench_mode);
void				rb(t_stack **b, t_operation_count *op_count,
						bool bench_mode);
void				rr(t_stack **a, t_stack **b, t_operation_count *op_count,
						bool bench_mode);

void				rra(t_stack **a, t_operation_count *op_count,
						bool bench_mode);
void				rrb(t_stack **b, t_operation_count *op_count,
						bool bench_mode);
void				rrr(t_stack **a, t_stack **b, t_operation_count *op_count,
						bool bench_mode);

double				compute_disorder(t_stack *a);

// Sort
void				sort_simple(t_stack **a, t_stack **b,
						t_operation_count *op_count, bool bench_mode);
void				sort_medium(t_stack **a, t_stack **b,
						t_operation_count *op_count, bool bench_mode);
void				push_chunk_to_b(t_chunk_params *params,
						t_operation_count *op_count, bool bench_mode);
void				move_back_to_a(t_stack **stack_a, t_stack **stack_b,
						t_operation_count *op_count, bool bench_mode);
void				chunk_sort(t_stack **a, t_stack **b,
						t_operation_count *op_count, bool bench_mode);
int					*prepare_sorted_array(t_stack *s, int size);
void				sort_complex(t_stack **a, t_stack **b,
						t_operation_count *op_count, bool bench_mode);
void				sort_adaptive(t_stack **a, t_stack **b,
						t_operation_count *op_count, bool bench_mode);
void				print_benchmark(t_operation_count *op_count,
						double disorder, const char *strategy,
						const char *complexity);
#endif