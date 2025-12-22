#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef	struct s_stack
{
	int				value;
	struct	s_stack *next;
}	t_stack;

void		error(void);
t_stack 	*parse_args(int argc, char **argv);
char    	**ft_split(char const *s, char c);
int			is_valid_number(char *str);
long		ft_atol(const char *str);
void    	free_split(char **split);

#endif