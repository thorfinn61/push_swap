#include "push_swap.h"

void parse_argument(char *arg, t_stack **a);
void parse_number(char *str, t_stack **a);

t_stack *parse_args(int argc, char **argv)
{
    t_stack *a;
    int     i;

    a = NULL;
    i = 1;
    while (i < argc)
    {
        parse_argument(argv[i], &a);
        i++;
    }
    return (a);
} 
void parse_argument(char *arg, t_stack **a)
{
    char    **words;
    int     j;

    words = ft_split(arg, ' ');
    if (!words || !words[0])
        error();
    j = 0;
    while (words[j])
    {
        parse_number(words[j], a);
        j++;
    }
    free_split(words);
}
void parse_number(char *str, t_stack **a)
{
    long n;
	t_stack	*tmp;

    if (!is_valid_number(str))
        error();
    n = ft_atol(str);
    if (n < INT_MIN || n > INT_MAX)
	{
        error();
	}
	tmp = *a;
	while (tmp)
	{
		if (tmp->value == (int)n)
			error();
		tmp = tmp->next;
	}
    stack_add_back(a, stack_new((int)n));
}

int	parse_flag(int ac, char **av, int *strat, int *bench)
{
	int i;

	*strat = 0;
	*bench = 0;
	i = 1;
	while (i < ac)
	{
		if (ft_strncmp(av[i], "--", 2) != 0)
			break;
		if (ft_strncmp(av[i], "--bench", 8) == 0)
			*bench = 1;
		else if (ft_strncmp(av[i], "--simple", 9) == 0)
			*strat = 1;
		else if (ft_strncmp(av[i], "--medium", 9) == 0)
			*strat = 2;
		else if (ft_strncmp(av[i], "--complex", 10) == 0)
			*strat = 3;
		else if (ft_strncmp(av[i], "--adaptative", 11) == 0)
			*strat = 4;
		else
			error();
		i++;
	}
	return (i);
}

