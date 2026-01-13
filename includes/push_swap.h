/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:41:20 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/13 11:08:24 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_cost
{
	int				a;
	int				b;
}					t_cost;

typedef struct s_bench
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
	int				total_vals;
}					t_bench;

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
	t_bench			*bench;
}					t_chunk_data;

typedef struct s_chunk_params
{
	t_stack			**stack_a;
	t_stack			**stack_b;
	int				chunk_min;
	int				chunk_max;
	t_bench			*bench;
}					t_chunk_params;

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
void				sa(t_stack **a, t_bench *b);
void				sb(t_stack **b, t_bench *bench);
void				ss(t_stack **a, t_stack **b, t_bench *bench);

void				pa(t_stack **a, t_stack **b, t_bench *bench);
void				pb(t_stack **a, t_stack **b, t_bench *bench);

void				ra(t_stack **a, t_bench *b);
void				rb(t_stack **b, t_bench *bench);
void				rr(t_stack **a, t_stack **b, t_bench *bench);

void				rra(t_stack **a, t_bench *b);
void				rrb(t_stack **b, t_bench *bench);
void				rrr(t_stack **a, t_stack **b, t_bench *bench);

double				compute_disorder(t_stack *a);

void				print_bench(t_bench *b, int strat, int used_strat,
						double disorder);

// Sort
void				sort_simple(t_stack **a, t_stack **b, t_bench *bench);
void				sort_medium(t_stack **a, t_stack **b, t_bench *bench);
void				chunk_sort(t_stack **a, t_stack **b, t_bench *bench);
int					*prepare_sorted_array(t_stack *s, int size);
void				push_chunk_to_b(t_chunk_params *params);
void				move_back_to_a(t_stack **stack_a, t_stack **stack_b,
						t_bench *bench);
void				sort_complex(t_stack **a, t_stack **b, t_bench *bench);
int					sort_adaptive(t_stack **a, t_stack **b, t_bench *bench);

// Turkish Utils
int					get_min_val(t_stack *stack);
int					get_max_val(t_stack *stack);
int					get_index(t_stack *stack, int value);
int					get_target_pos(t_stack *a, int val_b);
int					find_cheapest(t_stack *a, t_stack *b, int *best_ca,
						int *best_cb);
void				execute_move(t_stack **a, t_stack **b, t_cost cost,
						t_bench *s);

#endif
