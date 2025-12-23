#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef	struct s_stack
{
	int				value;
	struct	s_stack *next;
}	t_stack;

void		error(void);

//Parser
t_stack 	*parse_args(int argc, char **argv);
char    	**ft_split(char const *s, char c);
int			is_valid_number(char *str);
long		ft_atol(const char *str);
void    	free_split(char **split);

//Stack
t_stack *stack_new(int value);
void    stack_add_back(t_stack **stack, t_stack *new);
int     stack_size(t_stack *stack);
int     is_sorted(t_stack *stack);
void	free_stack(t_stack *stack);

//Instruction
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);


double	compute_disorder(t_stack *a);

//Sort
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void 	sort_five(t_stack **a, t_stack **b);
void	sort_simple(t_stack **a, t_stack **b );
void	sort_medium(t_stack **a, t_stack **b);
void	sort_complex(t_stack **a, t_stack **b);
void	sort_adaptive(t_stack **a, t_stack **b);
#endif