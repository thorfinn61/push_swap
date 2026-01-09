/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:23:49 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/09 17:08:54 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_format(char c, va_list *args, int fd, int *count);

int	ft_dprintf(int fd, const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			handle_format(format[i + 1], &args, fd, &count);
			i += 2;
		}
		else
		{
			write(fd, &format[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			handle_format(format[i + 1], &args, 1, &count);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}

static void	handle_pointer(va_list *args, int fd, int *count)
{
	void	*ptr;

	ptr = va_arg(*args, void *);
	if (!ptr)
		ft_putstr_fd("(nil)", fd, count);
	else
	{
		ft_putstr_fd("0x", fd, count);
		ft_putnbr_base_ul((unsigned long)ptr, "0123456789abcdef", fd, count);
	}
}

void	handle_format(char c, va_list *args, int fd, int *count)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(*args, int), fd, count);
	else if (c == 's')
		ft_putstr_fd(va_arg(*args, char *), fd, count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(*args, int), fd, count);
	else if (c == '%')
		ft_putchar_fd('%', fd, count);
	else if (c == 'u')
		ft_putnbr_base_ul(va_arg(*args, unsigned int), "0123456789", fd, count);
	else if (c == 'x')
		ft_putnbr_base_ul(va_arg(*args, unsigned int), "0123456789abcdef",
			fd, count);
	else if (c == 'X')
		ft_putnbr_base_ul(va_arg(*args, unsigned int), "0123456789ABCDEF",
			fd, count);
	else if (c == 'p')
		handle_pointer(args, fd, count);
}
