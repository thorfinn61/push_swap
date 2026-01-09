/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:53:25 by elsahin           #+#    #+#             */
/*   Updated: 2026/01/09 17:09:43 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
void	ft_putchar_fd(char c, int fd, int *count);
void	ft_putstr_fd(char *s, int fd, int *count);
void	ft_putnbr_fd(int n, int fd, int *count);
void	ft_putnbr_base_ul(unsigned long n, char *base, int fd, int *count);

#endif
