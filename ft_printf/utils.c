/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:24:13 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/09 17:09:19 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd, int *count)
{
	write(fd, &c, 1);
	(*count)++;
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	if (!s)
	{
		write(fd, "(null)", 6);
		*count += 6;
		return ;
	}
	while (*s)
	{
		write(fd, s, 1);
		s++;
		(*count)++;
	}
}

void	ft_putnbr_fd(int n, int fd, int *count)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*count += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd, count);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd, count);
	ft_putchar_fd((n % 10) + '0', fd, count);
}

void	ft_putnbr_base_ul(unsigned long n, char *base, int fd, int *count)
{
	unsigned long	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
		ft_putnbr_base_ul(n / base_len, base, fd, count);
	ft_putchar_fd(base[n % base_len], fd, count);
}
