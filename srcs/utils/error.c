/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:38:38 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/19 13:50:33 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_error(t_stack *a, char **words)
{
	if (a)
		free_stack(a);
	if (words)
		free_split(words);
	error();
}
