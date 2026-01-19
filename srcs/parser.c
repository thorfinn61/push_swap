/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:38:01 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/19 10:54:58 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_argument(char *arg, t_stack **a);
void	parse_number(char *str, t_stack **a);

t_stack	*parse_args(int argc, char **argv, int *strat, int *bench)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = parse_flag(argc, argv, strat, bench);
	while (i < argc)
	{
		parse_argument(argv[i], &a);
		i++;
	}
	return (a);
}

void	parse_argument(char *arg, t_stack **a)
{
	char	**words;
	int		j;

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

void	parse_number(char *str, t_stack **a)
{
	long	n;
	t_stack	*tmp;

	if (!is_valid_number(str))
		error();
	n = ft_atol(str);
	if (n < INT_MIN || n > INT_MAX)
		error();
	tmp = *a;
	while (tmp)
	{
		if (tmp->value == (int)n)
			error();
		tmp = tmp->next;
	}
	stack_add_back(a, stack_new((int)n));
}

static void	process_flag(char *s, int *strat, int *bench)
{
	if (!ft_strncmp(s, "--bench", 8))
	{
		if (*bench)
			error();
		*bench = 1;
	}
	else if (!ft_strncmp(s, "--simple", 9) && *strat == -1)
		*strat = 1;
	else if (!ft_strncmp(s, "--medium", 9) && *strat == -1)
		*strat = 2;
	else if (!ft_strncmp(s, "--complex", 10) && *strat == -1)
		*strat = 3;
	else if (!ft_strncmp(s, "--adaptive", 11) && *strat == -1)
		*strat = 0;
	else
		error();
}

int	parse_flag(int ac, char **av, int *strat, int *bench)
{
	int	i;

	*strat = -1;
	*bench = 0;
	i = 1;
	while (i < ac)
	{
		if (ft_strncmp(av[i], "--", 2) != 0)
			break ;
		process_flag(av[i], strat, bench);
		i++;
	}
	if (*strat == -1)
		*strat = 0;
	return (i);
}
