/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:00:00 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/13 15:18:16 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_rotates(char *line, t_stack **a, t_stack **b, t_bench *bench)
{
	if (!ft_strncmp(line, "ra\n", 3))
		ra(a, bench);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b, bench);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b, bench);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a, bench);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b, bench);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b, bench);
	else
		error();
}

static void	exec_instruction(char *line, t_stack **a, t_stack **b)
{
	t_bench	bench;

	bench = (t_bench){0};
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a, &bench);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b, &bench);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b, &bench);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b, &bench);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(a, b, &bench);
	else
		exec_rotates(line, a, b, &bench);
}

static char	*get_next_line_simple(void)
{
	char	*line;
	char	buf[1];
	int		i;
	char	temp[10000];

	i = 0;
	while (read(0, buf, 1) > 0)
	{
		temp[i++] = buf[0];
		if (buf[0] == '\n' || i >= 9999)
			break ;
	}
	if (i == 0)
		return (NULL);
	temp[i] = '\0';
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (temp[++i])
		line[i] = temp[i];
	line[i] = '\0';
	return (line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		strat;
	int		bench;
	char	*line;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv, &strat, &bench);
	b = NULL;
	while (1)
	{
		line = get_next_line_simple();
		if (!line)
			break ;
		exec_instruction(line, &a, &b);
		free(line);
	}
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(a);
	free_stack(b);
	return (0);
}
